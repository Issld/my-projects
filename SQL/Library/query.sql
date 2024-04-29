--Select part
SELECT place_id, shelfName, rowNum, columnNum FROM LibrarySchema.place;
SELECT book_id, bookName, autorSurname, autorName, autorPatronimic, isGiven, summary, place_id FROM LibrarySchema.book;
SELECT book_id, bookName, AutorSurname, AutorName, AutorPatronimic, summary FROM LibrarySchema.bookArchive;
SELECT bookName, autorSurname, autorName, autorPatronimic, summary FROM LibrarySchema.UserView;
SELECT person_id, persSurname, persName, persPatronimic FROM LibrarySchema.libraryCard;
SELECT person_id, persSurname, persName, persPatronimic FROM LibrarySchema.libraryCardArchive;
SELECT order_id, book_id, person_id, issueDate FROM "LibraySchema".givenBook;
SELECT archiveOrder_id, order_id, book_id, person_id, issueDate, returnDate FROM LibrarySchema.givenBackBook;
SELECT order_id, bookName, autorSurname, autorName, autorPatronimic, person_id FROM LibrarySchema.activeOrder;

--Truncate part
TRUNCATE TABLE LibrarySchema.place;
TRUNCATE TABLE LibrarySchema.book;
TRUNCATE TABLE LibrarySchema.bookArchive;
TRUNCATE TABLE LibrarySchema.libraryCard;
TRUNCATE TABLE LibrarySchema.libraryCardArchive;
TRUNCATE TABLE LibrarySchema.givenBook;
TRUNCATE TABLE LibrarySchema.givenBackBook;
TRUNCATE TABLE LibrarySchema.activeOrder;

--Insert part
INSERT INTO LibrarySchema.place (place_id, shelfName, rowNum, columnNum)
VALUES();
INSERT INTO LibrarySchema.book (book_id, bookName, autorSurname, autorName, autorPatronimic, isGiven, summary, place_id) 
VALUES();
INSERT INTO LibrarySchema.bookArchive (book_id, bookName, AutorSurname, AutorName, AutorPatronimic, summary)
VALUES();
INSERT INTO LibrarySchema.libraryCard (person_id, persSurname, persName, persPatronimic)
VALUES(); 
INSERT INTO LibrarySchema.libraryCardArchive (person_id, persSurname, persName, persPatronimic)
VALUES();
INSERT INTO LibrarySchema.givenBook (order_id, book_id, person_id, issueDate)
VALUES();
INSERT INTO LibrarySchema.givenBackBook (archiveOrder_id, order_id, book_id, person_id, issueDate, returnDate)
VALUES();
INSERT INTO LibrarySchema.activeOrder (archiveOrder_id, order_id, book_id, person_id, issueDate, returnDate)
VALUES();

--Update part
UPDATE LibrarySchema.place SET
WHERE;
UPDATE LibrarySchema.book SET
WHERE;
UPDATE LibrarySchema.bookArchive SET
WHERE;
UPDATE LibrarySchema.libraryCard SET
WHERE;
UPDATE LibrarySchema.libraryCard SET
WHERE;
UPDATE LibrarySchema.givenBook SET
WHERE;
UPDATE LibrarySchema.givenBackBook SET
WHERE;
UPDATE LibrarySchema.activeOrder SET
WHERE;

--Delete part
DELETE FROM LibrarySchema.place
WHERE;
DELETE FROM LibrarySchema.book
WHERE;
DELETE FROM LibrarySchema.bookArchive
WHERE;
DELETE FROM LibrarySchema.libraryCard
WHERE;
DELETE FROM LibrarySchema.libraryCard
WHERE;
DELETE FROM LibrarySchema.givenBook
WHERE;
DELETE FROM LibrarySchema.givenBackBook
WHERE;
DELETE FROM LibrarySchema.activeOrder
WHERE;