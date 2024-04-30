CREATE TYPE points AS(
	russian integer,
	math integer,
	other integer
);

CREATE TABLE worker(
	person_id serial PRIMARY KEY,
	surname varchar(30) NOT NULL,
	pname varchar(30) NOT NULL,
	patronimic varchar(30),
	isInspected bool
);

CREATE TABLE student
(
	PRIMARY KEY (person_id),
	st_group integer,
	EGE points
) INHERITS (worker);

CREATE TABLE fluorography(
	flu_id integer PRIMARY KEY,
	DateOfPass date
);

CREATE TABLE vaccine(
	vac_id integer PRIMARY KEY,
	illness varchar(25)
);

CREATE TABLE worker_flu
(
	worker_flu_id integer PRIMARY KEY,
	person_id integer,
	flu_id integer NOT NULL REFERENCES fluorography(flu_id) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE worker_vac
(
	worker_vac_id integer PRIMARY KEY,
	person_id integer,
	vac_id integer NOT NULL REFERENCES vaccine(vac_id) ON UPDATE CASCADE ON DELETE CASCADE
);