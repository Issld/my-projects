/*CREATE TABLE back_up_person
(
	back_id serial PRIMARY KEY,
	person_id_old integer,
	surname_old varchar(30) NOT NULL,
	pname_old varchar(30) NOT NULL,
	patronimic_old varchar(30),
	birthday_old date NOT NULL,
	extrainf_old varchar(255),
	refresh_time time,
	refresh_date date
);

TRUNCATE TABLE back_up_person RESTART IDENTITY*/

CREATE OR REPLACE FUNCTION insert_inf_fun() RETURNS TRIGGER AS $$
BEGIN
IF NEW.extrainf IS NULL
THEN NEW.extrainf := 'No extra information about person';
END IF;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER insert_inf
BEFORE INSERT ON person
FOR EACH ROW
EXECUTE PROCEDURE insert_inf_fun();

CREATE OR REPLACE FUNCTION back_up_fun() RETURNS TRIGGER AS $$
BEGIN
INSERT INTO back_up_person (person_id_old, surname_old, pname_old, patronimic_old, birthday_old, extrainf_old, refresh_time, refresh_date)
VALUES(OLD.person_id, OLD.surname, OLD.pname, OLD.patronimic, OLD.birthday, OLD.extrainf, (SELECT CURRENT_TIME), (SELECT CURRENT_DATE));
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER back_up_update 
BEFORE UPDATE ON person
FOR EACH ROW
EXECUTE PROCEDURE back_up_fun();

CREATE OR REPLACE FUNCTION ins_phone_to_person() RETURNS TRIGGER AS $$
BEGIN
UPDATE person SET phone_count = phone_count + 1 WHERE person_id = NEW.person_id;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER count_phones_ins 
AFTER INSERT ON phone
FOR EACH ROW
EXECUTE PROCEDURE ins_phone_to_person();

CREATE OR REPLACE FUNCTION upd_phone_to_person() RETURNS TRIGGER AS $$
BEGIN
UPDATE person SET phone_count = phone_count + 1 WHERE person_id = NEW.person_id;
UPDATE person SET phone_count = phone_count - 1 WHERE person_id = OLD.person_id;
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER count_phones_upd 
AFTER UPDATE ON phone
FOR EACH ROW
EXECUTE PROCEDURE upd_phone_to_person();

CREATE OR REPLACE FUNCTION del_phone_to_person() RETURNS TRIGGER AS $$
BEGIN
UPDATE person SET phone_count = phone_count - 1 WHERE person_id = OLD.person_id;
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER count_phones_del 
AFTER DELETE ON phone
FOR EACH ROW
EXECUTE PROCEDURE del_phone_to_person();

CREATE OR REPLACE FUNCTION cascade_delete_fun() RETURNS TRIGGER AS $$
BEGIN
DELETE FROM mark_table WHERE mark_table.person_id = OLD.person_id;
DELETE FROM holiday_table WHERE holiday_table.person_id = OLD.person_id;
ALTER TABLE phone DISABLE TRIGGER count_phones_del;
DELETE FROM phone WHERE phone.person_id = OLD.person_id;
ALTER TABLE phone ENABLE TRIGGER count_phones_del;
DELETE FROM mail WHERE mail.person_id = OLD.person_id;
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER cascade_delete
BEFORE DELETE ON person
FOR EACH ROW
EXECUTE PROCEDURE cascade_delete_fun();

/*DROP TRIGGER insert_inf ON person;
DROP TRIGGER back_up_update ON person;
DROP TRIGGER cascade_delete ON person;
DROP TRIGGER count_phones_ins ON phone;
DROP TRIGGER count_phones_upd ON phone;
DROP TRIGGER count_phones_del ON phone;*/

/*SELECT * FROM person ORDER BY person_id;
SELECT * FROM phone;
SELECT * FROM mail;
SELECT * FROM mark_table;
SELECT * FROM holiday_table;
SELECT * FROM back_up_person;*/

/*INSERT into person (person_id, surname, pname, patronimic, birthday, phone_count)
values
(6, 'Максимов', 'Максим', 'Максимович', '06-06-2006', 0);
UPDATE person SET surname = 'Петроов' WHERE surname = 'Петров';
DELETE FROM person WHERE person_id = 2;
INSERT into phone
values
('+7442055985', 6);
DELETE FROM phone WHERE phone_number = '+7442055985';
UPDATE phone SET person_id = 3 WHERE phone_number = '+7442055985';*/