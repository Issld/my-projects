CREATE OR REPLACE PROCEDURE insert_phone(phone_num varchar(12), surname_new varchar(30), pname_new varchar(30), birthday_new date) AS $$
DECLARE pers_id_new integer;
BEGIN
IF EXISTS (SELECT * FROM person WHERE surname_new = surname AND pname_new = pname AND birthday_new = birthday)
THEN SELECT person_id INTO pers_id_new FROM person
WHERE surname_new = surname AND pname_new = pname AND birthday_new = birthday;
ELSE BEGIN
pers_id_new := (SELECT COALESCE(MAX(person_id)+1, 0) FROM person);
INSERT INTO person(person_id, surname, pname, birthday)
VALUES (pers_id_new, surname_new, pname_new, birthday_new);
END;
END IF;
IF NOT EXISTS (SELECT * FROM phone WHERE phone_num = phone_number)
THEN INSERT INTO phone(phone_number, person_id)
VALUES(phone_num, pers_id_new);
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE delete_phone_clear_person(phone_num varchar(12)) AS $$
DECLARE pers_id_del integer;
BEGIN
IF EXISTS (SELECT * FROM phone WHERE phone_num = phone_number)
THEN SELECT person_id INTO pers_id_del FROM phone
WHERE phone_num = phone_number;
END IF;
DELETE FROM phone WHERE phone_num = phone_number;
IF NOT EXISTS(SELECT * FROM phone WHERE person_id = pers_id_del)
THEN DELETE FROM person WHERE pers_id_del = person_id;
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE delete_person_cascade(pers_id int) AS $$
BEGIN
DELETE FROM mark_table WHERE person_id = pers_id;
DELETE FROM holiday_table WHERE person_id = pers_id;
DELETE FROM phone WHERE person_id = pers_id;
DELETE FROM mail WHERE person_id = pers_id;
DELETE FROM person WHERE person_id = pers_id;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE count_person_out(OUT count_pers int) AS $$
BEGIN
SELECT COALESCE(COUNT(person_id), 0) INTO count_pers FROM person;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION count_person_out_fun(OUT count_pers int) AS $$
BEGIN
SELECT COALESCE(COUNT(person_id), 0) INTO count_pers FROM person;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION count_person_return_with_plpgsql() RETURNS int AS $$
DECLARE count_pers int;
BEGIN
count_pers := (SELECT COALESCE(COUNT(person_id), 0) FROM person);
RETURN count_pers;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION count_person_return_with_sql() RETURNS int AS $$
SELECT COALESCE(COUNT(person_id), 0) FROM person
$$ LANGUAGE SQL;

CREATE OR REPLACE FUNCTION create_stat_fun() 
RETURNS TABLE(id_p int, m_count int, h_count int, p_count int, ma_count int) AS $$
BEGIN
CREATE TEMPORARY TABLE stat_table
(id_stat serial PRIMARY KEY,
id_person int,
mark_count int,
holiday_count int,
phone_count int,
mail_count int);
INSERT INTO stat_table (id_person, mark_count)
SELECT DISTINCT person.person_id, COUNT(mark_id) from person
LEFT JOIN mark_table USING(person_id)
GROUP BY person.person_id;
UPDATE stat_table SET holiday_count = COALESCE((SELECT holiday_id_time 
									 FROM (SELECT person.person_id as pers, COUNT(holiday_id) as holiday_id_time 
										   FROM person
										   JOIN holiday_table USING(person_id)
										   GROUP BY person.person_id) AS qu WHERE stat_table.id_person = pers), 0);
UPDATE stat_table SET phone_count = COALESCE((SELECT phone_numb 
									 FROM (SELECT person.person_id as pers, COUNT(phone_number) as phone_numb 
										   FROM person
										   JOIN phone USING(person_id)
										   GROUP BY person.person_id) AS qur WHERE stat_table.id_person = pers), 0);
UPDATE stat_table SET mail_count = COALESCE((SELECT mail_time 
									 FROM (SELECT person.person_id as pers, COUNT(mailes) as mail_time
										   FROM person
										   JOIN mail USING(person_id)
										   GROUP BY person.person_id) AS qure WHERE stat_table.id_person = pers), 0);
RETURN QUERY(SELECT id_person, mark_count, holiday_count, phone_count, mail_count FROM stat_table);
DROP TABLE stat_table;
END;
$$ LANGUAGE plpgsql;

CALL insert_phone('+7412055985', 'Иванов', 'Иван', '01-01-2001');
CALL insert_phone('+7512055985', 'Пентров', 'Иван', '01-01-2001');
CALL delete_phone_clear_person('+7512055985');
CALL delete_person_cascade(2);
CALL count_person_out(NULL);
SELECT count_person_out_fun();
SELECT count_person_return_with_plpgsql();
SELECT count_person_return_with_sql();
SELECT id_p AS person_id, m_count AS mark_count, h_count AS holiday_count, p_count AS phone_count, ma_count
AS mail_count FROM create_stat_fun()
ORDER BY id_p;

--help
/*SELECT * FROM phone;
SELECT * FROM person;
TRUNCATE person, holiday, holiday_table, mail, mark, mark_table, person, phone;
DROP PROCEDURE delete_person_cascade(varchar(12));
DROP FUNCTION create_stat_fun();*/