INSERT INTO worker (surname, pname, patronimic, isInspected)
VALUES
('Петрова', 'Анастасия', 'Ивановна', true),
('Фелоров', 'Федор', 'Федорович', false);

INSERT INTO student (surname, pname, patronimic, isInspected, st_group, EGE)
VALUES
('Иванов', 'Иван', 'Иванович', true, 4000, ROW(95, 97, 89)),
('Евгеньева', 'Евгения', 'Евгениевна', true, 4001, ROW(87, 88, 90));

INSERT INTO fluorography(flu_id, DateOfPass)
VALUES
(1, '01-01-2024'),
(2, '02-01-2024'),
(3, '03-01-2024'),
(4, '04-01-2024');

INSERT INTO vaccine(vac_id, illness)
VALUES
(1, 'Корь'),
(2, 'Грипп'),
(3, 'Пневмония');

INSERT INTO worker_flu(worker_flu_id, person_id, flu_id)
VALUES
(1, 1, 1),
(2, 2, 2),
(3, 3, 3),
(4, 4, 4);

INSERT INTO worker_vac(worker_vac_id, person_id, vac_id)
VALUES
(1, 1, 1),
(2, 3, 1),
(3, 4, 1),
(4, 1, 2),
(5, 2, 2),
(6, 2, 3);

/*
SELECT * FROM worker;
SELECT * FROM student;
SELECT * FROM fluorography;
SELECT * FROM vaccine;
SELECT * FROM worker_flu;
SELECT * FROM worker_vac;
TRUNCATE TABLE worker, student RESTART IDENTITY;
*/