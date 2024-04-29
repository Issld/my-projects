CREATE OR REPLACE FUNCTION get_month_name(month_number numeric) RETURNS varchar(10) AS $$
	SELECT CASE WHEN month_number = 1 THEN 'январь'
		WHEN month_number = 2 THEN 'февраль'
		WHEN month_number = 3 THEN 'март'
		WHEN month_number = 4 THEN 'апрель'
		WHEN month_number = 5 THEN 'май'
		WHEN month_number = 6 THEN 'июнь'
		WHEN month_number = 7 THEN 'июль'
		WHEN month_number = 8 THEN 'август'
		WHEN month_number = 9 THEN 'сентябрь'
		WHEN month_number = 10 THEN 'октябрь'
		WHEN month_number = 11 THEN 'ноябрь'
		WHEN month_number = 12 THEN 'декабрь'
	END
$$ LANGUAGE SQL;

/*коллеги, у которых номер телефона начинается на 8-905, и заканчивается на 4*/
SELECT person.person_id, surname, pname, patronimic FROM person
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
INNER JOIN phone ON phone.person_id = person.person_id
WHERE dataa ='коллеги' AND phone_number LIKE '+7905%4';

/*Люди (контакты) без электронной почты*/
SELECT person.person_id, person.surname, person.pname, person.patronimic FROM person
RIGHT OUTER JOIN mail ON mail.person_id = person.person_id
WHERE mailes IS NULL;

/*люди, которые празднуют и 8 марта и Рождество*/
SELECT DISTINCT person.person_id, surname, pname, patronimic FROM person
INNER JOIN holiday_table ON holiday_table.person_id = person.person_id
INNER JOIN holiday_table AS sec_holiday_table ON sec_holiday_table.person_id = person.person_id
INNER JOIN holiday ON holiday.holiday_id = holiday_table.holiday_id
INNER JOIN holiday AS sec_holiday ON sec_holiday.holiday_id = sec_holiday.holiday_id
WHERE holiday.holiday_name = 'Новый год' AND sec_holiday.holiday_name = '8 марта';

/*самые старые люди среди друзей*/
/*SELECT person.person_id, surname, pname, patronimic, birthday FROM person
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE dataa = 'друзья' AND birthday = (SELECT MIN(birthday) FROM person);*/
SELECT person.person_id, surname, pname, patronimic, birthday FROM person
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE dataa = 'друзья' AND birthday <= ALL(SELECT birthday FROM person);

/*месяц, когда есть праздники у семьи, но нет у друзей через EXCEPT*/
SELECT get_month_name(EXTRACT(MONTH FROM holiday.holiday_day)) AS month_name FROM holiday
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'семья'
EXCEPT
SELECT get_month_name(EXTRACT(MONTH FROM holiday.holiday_day)) AS month_name FROM holiday
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'друзья'

/*месяц, когда есть праздники у семьи, но нет у друзей через NOT IN*/
SELECT get_month_name(EXTRACT(MONTH FROM holiday.holiday_day)) AS month_name FROM holiday
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'семья'
AND EXTRACT(MONTH FROM holiday.holiday_day)NOT IN 
(SELECT EXTRACT(MONTH FROM holiday.holiday_day) AS month_name FROM holiday 
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'друзья')

/*месяц, когда есть праздники у семьи, но нет у друзей через LEFT JOIN*/
SELECT get_month_name(EXTRACT(MONTH FROM holiday.holiday_day)) AS month_name FROM holiday
LEFT JOIN (SELECT EXTRACT(MONTH FROM holiday.holiday_day) AS m_name FROM holiday
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'друзья') AS other ON other.m_name = EXTRACT(MONTH FROM holiday.holiday_day)
INNER JOIN holiday_table ON holiday_table.holiday_id = holiday.holiday_id
INNER JOIN person ON person.person_id = holiday_table.person_id
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.mark_id
WHERE mark.dataa = 'семья' AND other.m_name IS NULL

/* метки, к которым относится количество людей больше среднего*/
SELECT dataa FROM mark
INNER JOIN mark_table ON mark_table.mark_id = mark.mark_id
GROUP BY dataa
HAVING COUNT(*) > (SELECT AVG(avg_count) FROM (SELECT COUNT(*) as avg_count FROM mark
INNER JOIN mark_table ON mark_table.mark_id = mark.mark_id
GROUP BY dataa) as time_query);

/*месяц, в котором есть дни рождения у людей в совокупности, относящихся ко всем меткам*/
/*Делитель метки
Делимое месяц*/
/*SELECT EXTRACT(MONTH FROM person.birthday) AS month_number FROM person
WHERE person_id IN (SELECT person.person_id FROM person
INNER JOIN mark_table ON mark_table.person_id = person.person_id
INNER JOIN mark ON mark.mark_id = mark_table.person_id
GROUP BY person.person_id
HAVING COUNT(*) = (SELECT COUNT(*) FROM mark));*/
SELECT get_month_name(EXTRACT(MONTH FROM person.birthday)) AS month_name FROM person
WHERE NOT EXISTS
(SELECT * FROM mark
WHERE NOT EXISTS 
(SELECT * FROM person AS pers 
INNER JOIN mark_table AS mark_t ON mark_t.person_id = pers.person_id
WHERE EXTRACT(MONTH FROM pers.birthday) >= EXTRACT(MONTH FROM person.birthday) AND mark_t.mark_id = mark.mark_id));


/*/*help*/
SELECT * FROM mark_table;
SELECT * FROM person;
SELECT * FROM holiday;*/