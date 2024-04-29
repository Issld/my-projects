CREATE OR REPLACE FUNCTION enter(login_try character varying, password_hash_try character varying) RETURNS TABLE(out_status bool, out_role integer, out_surname varchar(30), out_name varchar(30)) AS $$
BEGIN
IF EXISTS (SELECT * FROM account WHERE login_try = login AND password_hash_try = password_hash)
THEN 
RETURN QUERY (SELECT TRUE, u_role, u_surname, u_name FROM account WHERE login_try = login AND password_hash_try = password_hash);
ELSE RETURN QUERY (SELECT FALSE, -1, 'NO'::varchar(30), 'NO'::varchar(30));
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION difference(time_begin TIMESTAMP, time_end timestamp) RETURNS time AS $$
BEGIN
return time_end - time_begin;
END;
$$ LANGUAGE plpgsql;

CREATE TABLE account(
	login varchar(30) PRIMARY KEY,
	password_hash varchar(255) NOT NULL,
	u_role integer NOT NULL,
	u_surname varchar(30) NOT NULL,
	u_name varchar(30) NOT NULL
);

CREATE TABLE task(
	task_id serial PRIMARY KEY,
	phone_num varchar(15) NOT NULL,
	task_date date NOT NULL,
	status bool
);

CREATE TABLE archive(
	file_id serial PRIMARY KEY,
	file_name varchar(30) NOT NULL,
	file_date date NOT NULL,
	file_path varchar(255) NOT NULL
);

SELECT * FROM account;
INSERT INTO account (login, password_hash, u_role, u_surname, u_name)
VALUES
('First', '827ccb0eea8a706c4c34a16891f84e7b', 0, 'Чацкий', 'Александр'),
('Second', 'e10adc3949ba59abbe56e057f20f883e', 0, 'Каренина', 'Анна'),
('Super', 'fcea920f7412b5da7be0cf42b8c93759', 1, 'Раскольников', 'Радион'),
('q', '7694f4a66316e53c8cdd9d9954bd611d', 1, 'Базаров', 'Евгений'),
('w', 'f1290186a5d0b1ceab27f4e77c0c5d68', 0, 'Бездомный', 'Иван');

SELECT * FROM task;
INSERT INTO task(phone_num, task_date, status) 
VALUES
('+7312055985', '25-03-2024', false),
('+7559408039', '25-03-2024', false),
('+7156451617', '25-03-2024', false),
('+7828512701', '25-03-2024', false),
('+7334350042', '25-03-2024', false),
('+7905111114', '25-03-2024', false);
UPDATE task SET status = FALSE WHERE status = TRUE;

SELECT * FROM archive;
INSERT INTO archive (file_name, file_date, file_path)
VALUES
('record_36531.pdf', '25-03-2024', '/home/isd/Kurs/record/record_36531.pdf'),
('delivery_21595.pdf', '25-03-2024', '/home/isd/Kurs/delivery/delivery_21595.pdf');

TRUNCATE TABLE task RESTART IDENTITY;
TRUNCATE TABLE archive RESTART IDENTITY;

DROP TABLE IF EXISTS q_current, q_made_tasks, q_work;
DROP TABLE IF EXISTS w_current, w_made_tasks, w_work;
DROP TABLE account
DROP TABLE task
DROP TABLE archive

DROP FUNCTION enter(login_try character varying, password_hash_try character varying);
DROP FUNCTION difference(time_begin TIMESTAMP, time_end timestamp);