CREATE TABLE person
(
	person_id integer PRIMARY KEY,
	surname varchar(30) NOT NULL,
	pname varchar(30) NOT NULL,
	patronimic varchar(30),
	birthday date NOT NULL,
	extrainf varchar(255)
);

CREATE TABLE mark
(
	mark_id integer PRIMARY KEY,
	dataa varchar(255) NOT NULL
);

CREATE TABLE holiday
(
	holiday_id integer PRIMARY KEY,
	holiday_name varchar(255) NOT NULL
);

CREATE TABLE phone
(
	phone_number varchar(12) PRIMARY KEY,
	person_id integer REFERENCES person(person_id) on DELETE CASCADE on UPDATE CASCADE
);

CREATE TABLE mail
(
	mailes varchar(255) PRIMARY KEY,
	person_id integer REFERENCES person(person_id) on DELETE CASCADE on UPDATE CASCADE
);

CREATE TABLE mark_table
(
	person_id integer REFERENCES person(person_id) on DELETE CASCADE on UPDATE CASCADE,
	mark_id integer REFERENCES mark(mark_id) on DELETE CASCADE on UPDATE CASCADE,
	CONSTRAINT mark_table_id PRIMARY KEY (person_id, mark_id)
);

CREATE TABLE holiday_table
(
	person_id integer REFERENCES person(person_id) on DELETE CASCADE on UPDATE CASCADE,
	holiday_id integer REFERENCES holiday(holiday_id) on DELETE CASCADE on UPDATE CASCADE,
	CONSTRAINT holiday_table_id PRIMARY KEY (person_id, holiday_id) 
);

ALTER TABLE mark ADD COLUMN extra_data varchar(255);

ALTER TABLE mark DROP COLUMN extra_data;

INSERT into person
values
(10001, 'Иванов', 'Иван', 'Иванович', '01-01-2001'),
(10002, 'Петров', 'Петр', 'Петрович', '02-02-2002'),
(10003, 'Егоров', 'Егор', 'Егорович', '03-03-2003'),
(10004, 'Викторов', 'Виктор', 'Викторович', '04-04-2004'),
(10005, 'Борисов', 'Борис', 'Борисович', '05-05-2005');

INSERT into mark
values
(1, 'коллеги'),
(2, 'друзья'),
(3, 'семья');

INSERT into holiday
values
(1, 'Новый год'),
(2, '8 марта'),
(3, '23 февраля'),
(4, '9 мая'),
(5, '23 День народного единства');

INSERT into phone
values
('+7312055985', 1),
('+7559408039', 2),
('+7156451617', 3),
('+7828512701', 4),
('+7334350042', 5);

INSERT into mail
values
('gegisid-ele2@mail.ru', 1),
('sahidu_jido13@mail.ru', 2),
('sobuvot_ixu67@mail.ru', 3),
('bikezex_uba21@mail.ru', 4),
('gudab-igapu31@mail.ru', 5);

INSERT into mark_table
values
(10001, 1),
(10001, 2),
(10002, 3),
(10003, 3),
(10004, 2),
(10005, 2);

INSERT into holiday_table
values
(10001, 1),
(10001, 5),
(10002, 3),
(10003, 4),
(10004, 2),
(10005, 2);