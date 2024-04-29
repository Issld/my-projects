CREATE SCHEMA LibrarySchema;

CREATE TABLE LibrarySchema.place
(
	place_id integer PRIMARY KEY,
	shelfName varchar(10) NOT NULL,
	rowNum integer NOT NULL,
	columnNum integer NOT NULL
);

INSERT INTO LibrarySchema.place (place_id, shelfName, rowNum, columnNum)
VALUES 
(1, 'A', 1, 1),
(2, 'A', 1, 2),
(3, 'A', 1, 3),
(4, 'A', 2, 1),
(5, 'A', 2, 2),
(6, 'A', 2, 3),
(7, 'A', 3, 1),
(8, 'A', 3, 2),
(9, 'A', 3, 3),
(10, 'B', 1, 1),
(11, 'B', 1, 2),
(12, 'B', 1, 3),
(13, 'B', 2, 1),
(14, 'B', 2, 2),
(15, 'B', 2, 3),
(16, 'B', 3, 1),
(17, 'B', 3, 2),
(18, 'B', 3, 3),
(19, 'C', 1, 1),
(20, 'C', 1, 2),
(21, 'C', 1, 3),
(22, 'C', 2, 1),
(23, 'C', 2, 2),
(24, 'C', 2, 3),
(25, 'C', 3, 1),
(26, 'C', 3, 2),
(27, 'C', 3, 3),
(28, 'D', 1, 1),
(29, 'D', 1, 2),
(30, 'D', 1, 3),
(31, 'D', 2, 1),
(32, 'D', 2, 2),
(33, 'D', 2, 3),
(34, 'D', 3, 1),
(35, 'D', 3, 2),
(36, 'D', 3, 3),
(37, 'E', 1, 1),
(38, 'E', 1, 2),
(39, 'E', 1, 3),
(40, 'E', 2, 1),
(41, 'E', 2, 2),
(42, 'E', 2, 3),
(43, 'E', 3, 1),
(44, 'E', 3, 2),
(45, 'E', 3, 3),
(46, 'F', 1, 1),
(47, 'F', 1, 2),
(48, 'F', 1, 3),
(49, 'F', 2, 1),
(50, 'F', 2, 2);

CREATE TABLE LibrarySchema.book
(
	book_id integer PRIMARY KEY,
	bookName varchar(255) NOT NULL,
	autorSurname varchar(30) NOT NULL,
	autorName varchar(30) NOT NULL,
	autorPatronimic varchar(30),
	isGiven bool NOT NULL,
	summary varchar(255),
	place_id integer REFERENCES LibrarySchema.place(place_id) on DELETE CASCADE on UPDATE CASCADE
);

INSERT INTO LibrarySchema.book (book_id, bookName, autorSurname, autorName, autorPatronimic, isGiven, summary, place_id) 
VALUES 
(1, 'The Catcher in the Rye', 'Salinger', 'J.D.', 'N/A', false, 'A story about a teenage boy named Holden Caulfield who has been expelled from prep school', 1),
(2, 'To Kill a Mockingbird', 'Lee', 'Harper', 'N/A', true, 'A story about racial injustice in a small Alabama town during the Great Depression', 2),
(3, '1984', 'Orwell', 'George', 'N/A', false, 'A dystopian novel set in a totalitarian society where citizens are constantly monitored and controlled by the government', 3),
(4, 'Pride and Prejudice', 'Austen', 'Jane', 'N/A', false, 'A romantic novel set in Georgian England that follows the relationship between Elizabeth Bennet and Mr. Darcy', 4),
(5, 'The Great Gatsby', 'Fitzgerald', 'F. Scott', 'N/A', true, 'A story about the decadence and excess of the Jazz Age in America', 5),
(6, 'One Hundred Years of Solitude', 'Marquez', 'Gabriel Garcia', 'N/A', false, 'A magical realist novel that follows the Buendia family over seven generations in the fictional town of Macondo', 6),
(7, 'The Lord of the Rings', 'Tolkien', 'J.R.R.', 'N/A', false, 'A high fantasy novel that follows hobbit Frodo Baggins as he attempts to destroy the One Ring and defeat the evil Sauron', 7),
(8, 'The Hitchhikerś Guide to the Galaxy', 'Adams', 'Douglas', 'N/A', true, 'A comedic science fiction series that follows the misadventures of hapless human Arthur Dent and his alien friend Ford Prefect', 8),
(9, 'The Picture of Dorian Gray', 'Wilde', 'Oscar', 'N/A', false, 'A Gothic novel about a young man named Dorian Gray who becomes obsessed with his own beauty and youth', 9),
(10, 'The Adventures of Sherlock Holmes', 'Doyle', 'Arthur Conan', 'N/A', false, 'A collection of short stories featuring the famous detective Sherlock Holmes and his loyal companion Dr. Watson', 10),
(11, 'Brave New World', 'Huxley', 'Aldous', 'N/A', true, 'A dystopian novel set in a future society where citizens are genetically engineered and conditioned to conform to a rigid social hierarchy', 11),
(12, 'The Hobbit', 'Tolkien', 'J.R.R.', 'N/A', false, 'A childrenś fantasy novel that follows hobbit Bilbo Baggins as he goes on an adventure with a group of dwarves to reclaim their treasure from the dragon Smaug', 12),
(13, 'The Count of Monte Cristo', 'Dumas', 'Alexandre', 'N/A', false, 'A historical adventure novel about a man named Edmond Dantes who is wrongfully imprisoned and seeks revenge against those who betrayed him', 13),
(14, 'The Brothers Karamazov', 'Dostoevsky', 'Fyodor', 'N/A', true, 'A philosophical novel that explores themes of faith, morality, and free will through the story of three brothers and their father', 14),
(15, 'The Sun Also Rises', 'Hemingway', 'Ernest', 'N/A', false, 'A novel about a group of American and British expatriates who travel from Paris to Pamplona to watch the running of the bulls and engage in other hedonistic pursuits', 15),
(16, 'The Canterbury Tales', 'Chaucer', 'Geoffrey', 'N/A', false, 'A collection of stories told by a group of pilgrims traveling to Canterbury Cathedral in the 14th century', 16),
(17, 'Anna Karenina', 'Tolstoy', 'Leo', 'N/A', true, 'A tragic novel about a married woman named Anna Karenina who falls in love with a young cavalry officer and faces social ostracism as a result', 17),
(18, 'The Divine Comedy', 'Dante', 'Alighieri', 'N/A', false, 'An epic poem that describes Danteś journey through Hell, Purgatory, and Paradise', 18),
(19, 'The Trial', 'Kafka', 'Franz', 'N/A', false, 'A surreal novel about a man named Josef K. who is arrested and put on trial for a crime he may or may not have committed', 19),
(20, 'The Sound and the Fury', 'Faulkner', 'William', 'N/A', true, 'A novel that explores the decline of the Compson family in the American South through the perspectives of four different narrators', 20),
(21, 'The Odyssey', 'Homer', 'N/A', 'N/A', false, 'An epic poem that follows the Greek hero Odysseus as he journeys home from the Trojan War', 21),
(22, 'Moby-Dick', 'Melville', 'Herman', 'N/A', false, 'A novel about a whaling voyage led by Captain Ahab and his obsessive quest for revenge against the white whale that took his leg', 22),
(23, 'Crime and Punishment', 'Dostoevsky', 'Fyodor', 'N/A', false, 'A psychological novel about a young man named Raskolnikov who commits a murder and struggles with guilt and redemption', 23),
(24, 'Heart of Darkness', 'Conrad', 'Joseph', 'N/A', true, 'A novella that explores the darkness at the heart of human nature through the story of a journey up the Congo River in Africa', 24),
(25, 'The Iliad', 'Homer', 'N/A', 'N/A', false, 'An epic poem that tells the story of the Trojan War and the hero Achilles', 25),
(26, 'The Stranger', 'Camus', 'Albert', 'N/A', false, 'A novel about a man named Meursault who kills an Arab and faces trial for his crime', 26),
(27, 'The Scarlet Letter', 'Hawthorne', 'Nathaniel', 'N/A', false, 'A novel set in Puritan New England that follows the story of Hester Prynne, who is forced to wear a scarlet letter "A" as punishment for adultery', 27),
(28, 'The Grapes of Wrath', 'Steinbeck', 'John', 'N/A', true, 'A novel that follows the Joad family as they migrate from Oklahoma to California during the Great Depression in search of work and a better life', 28),
(29, 'The Trial and Death of Socrates', 'Plato', 'N/A', 'N/A', false, 'A collection of four dialogues that describe the trial and death of the philosopher Socrates', 29),
(30, 'The Canterbury Tales', 'Chaucer', 'Geoffrey', 'N/A', false, 'A collection of stories told by a group of pilgrims traveling to Canterbury Cathedral in the 14th century', 30),
(31, 'The Metamorphosis', 'Kafka', 'Franz', 'N/A', false, 'A novella about a man named Gregor Samsa who wakes up one morning to find that he has been transformed into a giant insect', 31),
(32, 'The Adventures of Tom Sawyer', 'Twain', 'Mark', 'N/A', false, 'A novel about a mischievous boy named Tom Sawyer and his adventures in the fictional town of St. Petersburg, Missouri', 32),
(33, 'The Importance of Being Earnest', 'Wilde', 'Oscar', 'N/A', true, 'A comedic play that satirizes Victorian society and its conventions', 33),
(34, 'The Old Man and the Sea', 'Hemingway', 'Ernest', 'N/A', false, 'A novella about an old fisherman named Santiago who goes on a long and difficult fishing expedition in the Gulf Stream off the coast of Cuba', 34),
(35, 'The Republic', 'Plato', 'N/A', 'N/A', false, 'A philosophical dialogue that explores ideas about justice, the nature of the soul, and the ideal society', 35),
(36, 'Wuthering Heights', 'Bronte', 'Emily', 'N/A', true, 'A Gothic novel about the destructive love between Catherine Earnshaw and Heathcliff on the moors of Yorkshire', 36),
(37, 'The Canterbury Tales', 'Chaucer', 'Geoffrey', 'N/A', false, 'A collection of stories told by a group of pilgrims traveling to Canterbury Cathedral in the 14th century', 37),
(38, 'The Divine Comedy', 'Dante', 'Alighieri', 'N/A', false, 'An epic poem that describes Danteś journey through Hell, Purgatory, and Paradise', 38),
(39, 'The Adventures of Huckleberry Finn', 'Twain', 'Mark', 'N/A', false, 'A novel that follows the adventures of Huck Finn and his friend Jim, a runaway slave, as they travel down the Mississippi River', 39),
(40, 'The Canterbury Tales', 'Chaucer', 'Geoffrey', 'N/A', false, 'A collection of stories told by a group of pilgrims traveling to Canterbury Cathedral in the 14th century', 40),
(41, 'The Aeneid', 'Virgil', 'N/A', 'N/A', false, 'An epic poem that tells the story of Aeneas and his journey from Troy to Italy, where he becomes the ancestor of the Roman people', 41),
(42, 'The Canterbury Tales', 'Chaucer', 'Geoffrey', 'N/A', false, 'A collection of stories told by a group of pilgrims traveling to Canterbury Cathedral in the 14th century', 42),
(43, 'Harry Potter and the Philosopherś Stone', 'Rowling', 'J.K.', 'N/A', true, 'A story about a young orphan boy named Harry Potter who discovers he is a wizard and attends a magical school', 43),
(44, 'The Hobbit', 'Tolkien', 'J.R.R.', 'N/A', false, 'A childrenś fantasy novel that follows hobbit Bilbo Baggins on his journey to reclaim treasure from a dragon', 44),
(45, 'The Da Vinci Code', 'Brown', 'Dan', 'N/A', true, 'A mystery thriller that follows symbologist Robert Langdon as he tries to solve a murder and uncover a religious conspiracy', 45),
(46, 'The Picture of Dorian Gray', 'Wilde', 'Oscar', 'N/A', true, 'A gothic novel that explores the themes of beauty, morality, and corruption through the story of a young man who remains youthful while his portrait ages', 46),
(47, 'The Adventures of Sherlock Holmes', 'Doyle', 'Arthur Conan', 'N/A', false, 'A collection of short detective stories featuring Sherlock Holmes and his partner Dr. Watson', 47),
(48, 'The Road', 'McCarthy', 'Cormac', 'N/A', true, 'A post-apocalyptic novel that follows a father and son as they journey through a desolate landscape', 48),
(49, 'The Cat in the Hat', 'Seuss', 'Dr.', 'N/A', false, 'A childrenś book about a mischievous cat who shows up at the house of two children and causes chaos', 49),
(50, 'The Adventures of Tom Sawyer', 'Twain', 'Mark', 'N/A', true, 'A coming-of-age story set in the fictional town of St. Petersburg, Missouri, that follows the adventures of young Tom Sawyer', 50);

CREATE TABLE LibrarySchema.bookArchive
(
	book_id integer PRIMARY KEY,
	bookName varchar(255) NOT NULL,
	autorSurname varchar(30) NOT NULL,
	autorName varchar(30) NOT NULL,
	autorPatronimic varchar(30),
	summary varchar(255)
);

INSERT INTO LibrarySchema.bookArchive (book_id, bookName, AutorSurname, AutorName, AutorPatronimic, summary)
VALUES
(1, 'The Catcher in the Rye', 'Salinger', 'J.D.', 'N/A', 'The story is told from the perspective of Holden Caulfield, a teenage boy who has been expelled from prep school. The novel is known for its themes of alienation and disillusionment.'),
(2, 'To Kill a Mockingbird', 'Lee', 'Harper', 'N/A', 'The story takes place in Alabama during the Great Depression and follows the life of a young girl named Scout Finch as she grows up and learns about racism and injustice.'),
(3, '1984', 'Orwell', 'George', 'N/A', 'The novel is set in a dystopian future where the government has complete control over every aspect of people”s lives. The story follows Winston Smith as he rebels against the oppressive regime.'),
(4, 'Pride and Prejudice', 'Austen', 'Jane', 'N/A', 'The novel follows the lives of the Bennet family, particularly the second eldest daughter Elizabeth, as she navigates the societal norms and expectations of 19th century England.'),
(5, 'Animal Farm', 'Orwell', 'George', 'N/A', 'The novel is an allegory for the Russian Revolution and the rise of Stalinism. The story follows a group of farm animals as they overthrow their human owner and attempt to create a society where the animals are equal.'),
(6, 'The Great Gatsby', 'Fitzgerald', 'F. Scott', 'N/A', 'The novel is set in the Roaring Twenties and follows the life of Jay Gatsby, a wealthy socialite who becomes obsessed with winning back his former love, Daisy Buchanan.'),
(7, 'One Hundred Years of Solitude', 'Marquez', 'Gabriel Garcia', 'N/A', 'The novel tells the story of the Buendía family over the course of seven generations in the fictional town of Macondo. The story is known for its magical realism and themes of solitude and isolation.'),
(8, 'Brave New World', 'Huxley', 'Aldous', 'N/A', 'The novel is set in a futuristic society where people are genetically engineered and conditioned to conform to societal norms. The story follows the life of Bernard Marx as he rebels against the system.'),
(9, 'The Hobbit', 'Tolkien', 'J.R.R.', 'N/A', 'The novel follows the adventures of hobbit Bilbo Baggins as he helps a group of dwarves reclaim their treasure from the dragon Smaug.'),
(10, 'The Lord of the Rings', 'Tolkien', 'J.R.R.', 'N/A', 'The novel follows hobbit Frodo Baggins as he embarks on a quest to destroy the One Ring and defeat the evil lord Sauron.'),
(11, 'The Hitchhiker”s Guide to the Galaxy', 'Adams', 'Douglas', 'N/A', 'The novel follows the misadventures of hapless human Arthur Dent as he travels through space with his alien friend Ford Prefect.'),
(12, 'The Da Vinci Code', 'Brown', 'Dan', 'N/A', 'The novel follows symbologist Robert Langdon as he investigates a murder at the Louvre and uncovers a conspiracy involving the Holy Grail.'),
(13, 'The Girl with the Dragon Tattoo', 'Larsson', 'Stieg', 'N/A', 'The novel follows journalist Mikael Blomkvist and hacker Lisbeth Salander as they investigate a decades-old disappearance and uncover a web of corruption and violence.'),
(14, 'The Hunger Games', 'Collins', 'Suzanne', 'N/A', 'The novel is set in a dystopian future where teenagers are forced to compete in a televised battle to the death. The story follows the life of protagonist Katniss Everdeen as she fights for survival.'),
(15, 'The Alchemist', 'Coelho', 'Paulo', 'N/A', 'The novel follows the journey of shepherd boy Santiago as he travels from Spain to Egypt in search of treasure and discovers the true meaning of life.'),
(16, 'Harry Potter and the Philosopher”s Stone', 'Rowling', 'J.K.', 'N/A', 'The novel follows the life of orphaned boy Harry Potter as he discovers that he is a wizard and attends Hogwarts School of Witchcraft and Wizardry.'),
(17, 'The Name of the Rose', 'Eco', 'Umberto', 'N/A', 'The novel is set in a medieval monastery and follows the investigation of a series of murders by Franciscan friar William of Baskerville.'),
(18, 'The Picture of Dorian Gray', 'Wilde', 'Oscar', 'N/A', 'The novel tells the story of Dorian Gray, a young man who sells his soul for eternal youth and beauty.'),
(19, 'The Adventures of Sherlock Holmes', 'Doyle', 'Arthur Conan', 'N/A', 'The novel is a collection of twelve short stories featuring detective Sherlock Holmes and his assistant Dr. John Watson.'),
(20, 'The Count of Monte Cristo', 'Dumas', 'Alexandre', 'N/A', 'The novel follows the life of Edmond Dantès, a man who is wrongfully imprisoned and seeks revenge against those who betrayed him.'),
(21, 'Les Misérables', 'Hugo', 'Victor', 'N/A', 'The novel is set in 19th century France and follows the lives of several characters, including ex-convict Jean Valjean and police inspector Javert, as they navigate the social and political upheaval of the time.'),
(22, 'Crime and Punishment', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel follows the life of impoverished student Raskolnikov as he commits a murder and struggles with guilt and redemption.'),
(23, 'Anna Karenina', 'Tolstoy', 'Leo', 'N/A', 'The novel tells the story of aristocrat Anna Karenina and her ill-fated affair with Count Vronsky.'),
(24, 'War and Peace', 'Tolstoy', 'Leo', 'N/A', 'The novel is set during the Napoleonic Wars and follows the lives of several aristocratic families as they navigate love, war, and politics.'),
(25, 'Moby-Dick; or, The Whale', 'Melville', 'Herman', 'N/A', 'The novel tells the story of Captain Ahab”s obsessive quest for revenge against the white whale that maimed him.'),
(26, 'The Adventures of Huckleberry Finn', 'Twain', 'Mark', 'N/A', 'The novel follows the adventures of Huck Finn and his friend Jim, a runaway slave, as they travel down the Mississippi River.'),
(27, 'The Brothers Karamazov', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel tells the story of the Karamazov family and their struggles with faith, morality, and patricide.'),
(28, 'Anna Karenina', 'Tolstoy', 'Leo', 'N/A', 'The novel tells the story of aristocrat Anna Karenina and her ill-fated affair with Count Vronsky.'),
(29, 'War and Peace', 'Tolstoy', 'Leo', 'N/A', 'The novel is set during the Napoleonic Wars and follows the lives of several aristocratic families as they navigate love, war, and politics.'),
(30, 'The Idiot', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel follows the life of Prince Myshkin as he navigates the complexities of Russian society.'),
(31, 'Crime and Punishment', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel follows the life of impoverished student Raskolnikov as he commits a murder and struggles with guilt and redemption.'),
(32, 'Eugene Onegin', 'Pushkin', 'Alexander', 'N/A', 'The novel in verse tells the story of Eugene Onegin and his ill-fated love for Tatyana.'),
(33, 'Doctor Zhivago', 'Pasternak', 'Boris', 'N/A', 'The novel follows the life of physician and poet Yuri Zhivago as he navigates the political upheaval of early 20th century Russia.'),
(34, 'One Day in the Life of Ivan Denisovich', 'Solzhenitsyn', 'Alexander', 'N/A', 'The novel is set in a Soviet labor camp and follows the life of prisoner Ivan Denisovich as he struggles to survive.'),
(35, 'Master and Margarita', 'Bulgakov', 'Mikhail', 'N/A', 'The novel blends satire, fantasy, and political commentary as it follows the devil and his retinue as they wreak havoc in Moscow.'),
(36, 'Dead Souls', 'Gogol', 'Nikolai', 'N/A', 'The novel tells the story of Chichikov, a con man who travels through Russia buying the souls of dead serfs.'),
(37, 'The Cherry Orchard', 'Chekhov', 'Anton', 'N/A', 'The play follows the lives of a group of aristocrats as they struggle to save their estate from foreclosure.'),
(38, 'Fathers and Sons', 'Turgenev', 'Ivan', 'N/A', 'The novel explores the generational divide between fathers and sons in 19th century Russia.'),
(39, 'The Queen of Spades', 'Pushkin', 'Alexander', 'N/A', 'The short story tells the tale of a young officer who becomes obsessed with a secret gambling strategy.'),
(49, 'The Master of Petersburg', 'Coetzee', 'J.M.', 'N/A', 'The novel follows the life of Fyodor Dostoevsky as he returns to St. Petersburg to investigate the death of his stepson.'),
(50, 'Eugene Onegin', 'Pushkin', 'Alexander', 'N/A', 'The novel in verse tells the story of Eugene Onegin and his ill-fated love for Tatyana.'),
(51, 'The White Guard', 'Bulgakov', 'Mikhail', 'N/A', 'The novel follows the lives of a family in Kiev during the Russian Civil War.'),
(52, 'A Hero of Our Time', 'Lermontov', 'Mikhail', 'N/A', 'The novel is a series of interconnected stories that explore the life of Pechorin, a Byronic hero.'),
(53, 'The Possessed', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel explores the political and social turmoil of 19th century Russia through the lives of a group of radicals.'),
(54, 'The Lady with the Dog', 'Chekhov', 'Anton', 'N/A', 'The short story tells the tale of a man who falls in love with a married woman while on vacation in Yalta.'),
(55, 'The Overcoat', 'Gogol', 'Nikolai', 'N/A', 'The short story tells the tale of a lowly clerk who becomes obsessed with obtaining a new coat.'),
(56, 'The Government Inspector', 'Gogol', 'Nikolai', 'N/A', 'The play satirizes the corruption and bureaucracy of the Russian government.'),
(57, 'The Master and Margarita', 'Bulgakov', 'Mikhail', 'N/A', 'The novel blends satire, fantasy, and political commentary as it follows the devil and his retinue as they wreak havoc in Moscow.'),
(58, 'Notes from Underground', 'Dostoevsky', 'Fyodor', 'N/A', 'The novella is told from the perspective of an unnamed narrator as he ruminates on his own misery and alienation from society.'),
(59, 'The Idiot', 'Dostoevsky', 'Fyodor', 'N/A', 'The novel follows the life of Prince Myshkin as he navigates the complexities of Russian society.'),
(60, 'Doctor Zhivago', 'Pasternak', 'Boris', 'N/A', 'The novel follows the life of physician and poet Yuri Zhivago as he navigates the political upheaval of early 20th century Russia.');

CREATE TABLE LibrarySchema.libraryCard
(
	person_id integer PRIMARY KEY,
	persSurname varchar(30) NOT NULL,
	persName varchar(30) NOT NULL,
	persPatronimic varchar(30)
);

INSERT INTO LibrarySchema.libraryCard (person_id, persSurname, persName, persPatronimic)
VALUES 
(1, 'Ivanov', 'Alex', 'Sergeevich'),
(2, 'Petrov', 'Dmitry', 'Ivanovich'),
(3, 'Sidorov', 'Maxim', 'Andreevich'),
(4, 'Kuznetsov', 'Vladimir', 'Viktorovich'),
(5, 'Smirnov', 'Igor', 'Nikolaevich'),
(6, 'Popov', 'Sergey', 'Petrovich'),
(7, 'Novikov', 'Anton', 'Ivanovich'),
(8, 'Morozov', 'Artem', 'Mikhailovich'),
(9, 'Fedorov', 'Yuri', 'Sergeevich'),
(10, 'Volkov', 'Roman', 'Andreevich'),
(11, 'Kuzmin', 'Mikhail', 'Dmitrievich'),
(12, 'Makarov', 'Ivan', 'Sergeevich'),
(13, 'Nikitin', 'Denis', 'Vladimirovich'),
(14, 'Kiselev', 'Alexey', 'Olegovich'),
(15, 'Sokolov', 'Evgeny', 'Valentinovich'),
(16, 'Gusev', 'Andrey', 'Petrovich'),
(17, 'Titov', 'Kirill', 'Ivanovich'),
(18, 'Vinogradov', 'Nikolay', 'Vladimirovich'),
(19, 'Kozlov', 'Vitaly', 'Sergeevich'),
(20, 'Zakharov', 'Egor', 'Dmitrievich'),
(21, 'Ryabov', 'Pavel', 'Andreevich'),
(22, 'Solovyov', 'Ilya', 'Mikhailovich'),
(23, 'Belyaev', 'Dmitry', 'Petrovich'),
(24, 'Kalinin', 'Artem', 'Sergeevich'),
(25, 'Zaytsev', 'Yaroslav', 'Andreevich'),
(26, 'Kudryavtsev', 'Sergey', 'Vladimirovich'),
(27, 'Baranov', 'Anton', 'Ivanovich'),
(28, 'Tikhonov', 'Vladislav', 'Sergeevich'),
(29, 'Komarov', 'Ivan', 'Andreevich'),
(30, 'Alekseev', 'Alexey', 'Dmitrievich'),
(31, 'Savin', 'Nikolay', 'Petrovich'),
(32, 'Karpov', 'Artem', 'Vladimirovich'),
(33, 'Nekrasov', 'Dmitry', 'Ivanovich'),
(34, 'Melnikov', 'Andrey', 'Sergeevich'),
(35, 'Belov', 'Maxim', 'Andreevich'),
(36, 'Semenov', 'Igor', 'Dmitrievich'),
(37, 'Frolov', 'Vladimir', 'Sergeevich'),
(38, 'Ignatov', 'Yuri', 'Andreevich'),
(39, 'Lapin', 'Pavel', 'Vladimirovich'),
(40, 'Filippov', 'Ilya', 'Ivanovich'),
(41, 'Bogdanov', 'Denis', 'Sergeevich'),
(42, 'Vlasov', 'Vladislav', 'Andreevich'),
(43, 'Sorokin', 'Ivan', 'Dmitrievich'),
(44, 'Konovalov', 'Anton', 'Vladimirovich'),
(45, 'Ponomarev', 'Artem', 'Ivanovich'),
(46, 'Fomin', 'Nikolay', 'Sergeevich'),
(47, 'Zueva', 'Anna', 'Andreevna'),
(48, 'Kiseleva', 'Maria', 'Dmitrievna'),
(49, 'Mironova', 'Olga', 'Sergeevna'),
(50, 'Sokolova', 'Elena', 'Andreevna'),
(51, 'Guseva', 'Natalia', 'Dmitrievna'),
(52, 'Titova', 'Tatiana', 'Sergeevna'),
(53, 'Vinogradova', 'Ekaterina', 'Andreevna'),
(54, 'Kozlova', 'Svetlana', 'Dmitrievna'),
(55, 'Zakharova', 'Alena', 'Sergeevna'),
(56, 'Ryabova', 'Anna', 'Andreevna'),
(57, 'Solovyova', 'Marina', 'Dmitrievna'),
(58, 'Belyaeva', 'Daria', 'Sergeevna'),
(59, 'Kalinina', 'Anastasia', 'Andreevna'),
(60, 'Zaytseva', 'Nadezhda', 'Dmitrievna');

CREATE TABLE LibrarySchema.libraryCardArchive
(
	person_id integer PRIMARY KEY,
	persSurname varchar(30) NOT NULL,
	persName varchar(30) NOT NULL,
	persPatronimic varchar(30)
);

INSERT INTO LibrarySchema.libraryCardArchive (person_id, persSurname, persName, persPatronimic)
VALUES 
(1, 'Ivanov', 'Alex', 'Sergeevich'),
(2, 'Petrov', 'Ivan', 'Dmitrievich'),
(3, 'Sidorov', 'Vladimir', 'Nikolaevich'),
(4, 'Kuznetsov', 'Sergey', 'Ivanovich'),
(5, 'Smirnov', 'Maxim', 'Andreevich'),
(6, 'Popov', 'Denis', 'Vladimirovich'),
(7, 'Novikov', 'Artem', 'Petrovich'),
(8, 'Morozov', 'Nikita', 'Igorevich'),
(9, 'Volkov', 'Roman', 'Mikhailovich'),
(10, 'Kozlov', 'Kirill', 'Sergeevich'),
(11, 'Lebedev', 'Anton', 'Alexandrovich'),
(12, 'Sokolov', 'Igor', 'Olegovich'),
(13, 'Korolev', 'Vitaly', 'Fedorovich'),
(14, 'Gusev', 'Dmitry', 'Pavlovich'),
(15, 'Kiselev', 'Vyacheslav', 'Vladimirovich'),
(16, 'Makarov', 'Andrei', 'Gennadievich'),
(17, 'Nikitin', 'Egor', 'Sergeevich'),
(18, 'Zakharov', 'Timofey', 'Yurievich'),
(19, 'Baranov', 'Alexey', 'Viktorovich'),
(20, 'Gavrilov', 'Ilya', 'Valerievich'),
(21, 'Vinogradov', 'Mikhail', 'Nikolaevich'),
(22, 'Belyaev', 'Nikolay', 'Vladimirovich'),
(23, 'Tarasov', 'Artem', 'Andreevich'),
(24, 'Belov', 'Vladislav', 'Sergeevich'),
(25, 'Krylov', 'Pavel', 'Ivanovich'),
(26, 'Melnikov', 'Fedor', 'Petrovich'),
(27, 'Fadeev', 'Dmitry', 'Vladimirovich'),
(28, 'Polovinkin', 'Sergey', 'Igorevich'),
(29, 'Suvorov', 'Ivan', 'Dmitrievich'),
(30, 'Karpov', 'Vladimir', 'Nikolaevich'),
(31, 'Kolesnikov', 'Maxim', 'Andreevich'),
(32, 'Golubev', 'Denis', 'Vladimirovich'),
(33, 'Bogdanov', 'Artem', 'Petrovich'),
(34, 'Vorobyov', 'Nikita', 'Igorevich'),
(35, 'Kudryavtsev', 'Roman', 'Mikhailovich'),
(36, 'Antonov', 'Kirill', 'Sergeevich'),
(37, 'Zaytsev', 'Anton', 'Alexandrovich'),
(38, 'Alekseev', 'Igor', 'Olegovich'),
(39, 'Gorbachev', 'Vitaly', 'Fedorovich'),
(40, 'Kuzmin', 'Dmitry', 'Pavlovich'),
(41, 'Kudinov', 'Vyacheslav', 'Vladimirovich'),
(42, 'Savin', 'Andrei', 'Gennadievich'),
(43, 'Vlasov', 'Egor', 'Sergeevich'),
(44, 'Frolov', 'Timofey', 'Yurievich'),
(45, 'Ponomarev', 'Alexey', 'Viktorovich'),
(46, 'Mironov', 'Ilya', 'Valerievich'),
(47, 'Klimov', 'Mikhail', 'Nikolaevich'),
(48, 'Fedorov', 'Nikolay', 'Vladimirovich'),
(49, 'Safonov', 'Artem', 'Andreevich'),
(50, 'Titov', 'Vladislav', 'Sergeevich');

CREATE TABLE LibrarySchema.givenBook
(
	order_id integer PRIMARY KEY,
	book_id integer REFERENCES LibrarySchema.book(book_id) on DELETE RESTRICT on UPDATE CASCADE,
	person_id integer REFERENCES  LibrarySchema.libraryCard(person_id) on DELETE RESTRICT on UPDATE CASCADE,
	issueDate date
);

INSERT INTO LibrarySchema.givenBook (order_id, book_id, person_id, issueDate)
VALUES
(1, 5, 10, '2024-01-01'),
(2, 3, 22, '2024-01-02'),
(3, 7, 36, '2024-01-03'),
(4, 2, 7, '2024-01-04'),
(5, 6, 18, '2024-01-05'),
(6, 1, 29, '2024-01-06'),
(7, 9, 44, '2024-01-07'),
(8, 4, 13, '2024-01-08'),
(9, 8, 27, '2024-01-09'),
(10, 10, 51, '2024-01-10'),
(11, 11, 15, '2024-01-11'),
(12, 12, 38, '2024-01-12'),
(13, 13, 49, '2024-01-13'),
(14, 14, 3, '2024-01-14'),
(15, 15, 46, '2024-01-15');

CREATE TABLE LibrarySchema.givenBackBook
(
	archiveOrder_id integer PRIMARY KEY,
	order_id integer,
	book_id integer,
	person_id integer,
	issueDate date,
	returnDate date
);

INSERT INTO LibrarySchema.givenBackBook (archiveOrder_id, order_id, book_id, person_id, issueDate, returnDate)
VALUES
(1, 31, 5, 10, '2024-02-01', '2024-02-10'),
(2, 32, 3, 22, '2024-02-02', '2024-02-12'),
(3, 33, 7, 36, '2024-02-03', '2024-02-13'),
(4, 34, 2, 7, '2024-02-04', '2024-02-14'),
(5, 35, 6, 18, '2024-02-05', '2024-02-15'),
(6, 36, 1, 29, '2024-02-06', '2024-02-16'),
(7, 37, 9, 44, '2024-02-07', '2024-02-17'),
(8, 38, 4, 13, '2024-02-08', '2024-02-18'),
(9, 39, 8, 27, '2024-02-09', '2024-02-19'),
(10, 40, 10, 51, '2024-02-10', '2024-02-20'),
(11, 41, 11, 15, '2024-02-11', '2024-02-21'),
(12, 42, 12, 38, '2024-02-12', '2024-02-22'),
(13, 43, 13, 49, '2024-02-13', '2024-02-23'),
(14, 44, 14, 3, '2024-02-14', '2024-02-24'),
(15, 45, 15, 46, '2024-02-15', '2024-02-25'),
(16, 46, 16, 21, '2024-02-16', '2024-02-26'),
(17, 47, 17, 35, '2024-02-17', '2024-02-27'),
(18, 48, 18, 50, '2024-02-18', '2024-02-28'),
(19, 49, 19, 8, '2024-02-19', '2024-03-01'),
(20, 50, 20, 41, '2024-02-20', '2024-03-02'),
(21, 51, 21, 16, '2024-02-21', '2024-03-03'),
(22, 52, 22, 33, '2024-02-22', '2024-03-04'),
(23, 53, 23, 47, '2024-02-23', '2024-03-05'),
(24, 54, 24, 26, '2024-02-24', '2024-03-06'),
(25, 55, 25, 42, '2024-02-25', '2024-03-07'),
(26, 56, 26, 11, '2024-02-26', '2024-03-08'),
(27, 57, 27, 40, '2024-02-27', '2024-03-09'),
(28, 58, 28, 5, '2024-02-28', '2024-03-10'),
(29, 59, 29, 30, '2024-03-01', '2024-03-11'),
(30, 60, 30, 54, '2024-03-02', '2024-03-12'),
(31, 61, 5, 10, '2024-03-03', '2024-03-13'),
(32, 62, 3, 22, '2021-03-04', '2024-03-14'),
(33, 63, 7, 36, '2024-03-05', '2024-03-15'),
(34, 64, 2, 7, '2024-03-06', '2024-03-16'),
(35, 65, 6, 18, '2024-03-07', '2024-03-17'),
(36, 66, 1, 29, '2024-03-08', '2024-03-18'),
(37, 67, 9, 44, '2024-03-09', '2024-03-19'),
(38, 68, 4, 13, '2024-03-10', '2024-03-20'),
(39, 69, 8, 27, '2024-03-11', '2024-03-21'),
(40, 70, 10, 51, '2024-03-12', '2024-03-22'),
(41, 71, 11, 15, '2024-03-13', '2024-03-23'),
(42, 72, 12, 38, '2024-03-14', '2024-03-24'),
(43, 73, 13, 49, '2024-03-15', '2024-03-25'),
(44, 74, 14, 3, '2024-03-16', '2024-03-26'),
(45, 75, 15, 46, '2024-03-17', '2024-03-27'),
(46, 76, 16, 21, '2024-03-18', '2024-03-28'),
(47, 77, 17, 35, '2024-03-19', '2024-03-29'),
(48, 78, 18, 50, '2024-03-20', '2024-03-30'),
(49, 79, 19, 8, '2024-03-21', '2024-03-31'),
(50, 80, 20, 41, '2024-03-22', '2024-04-01'),
(51, 81, 21, 16, '2024-03-23', '2024-04-02'),
(52, 82, 22, 33, '2024-03-24', '2024-04-03'),
(53, 83, 23, 47, '2024-03-25', '2024-04-04'),
(54, 84, 24, 26, '2024-03-26', '2024-04-05'),
(55, 85, 25, 42, '2024-03-27', '2024-04-06'),
(56, 86, 26, 11, '2024-03-28', '2024-04-07'),
(57, 87, 27, 40, '2024-03-29', '2024-04-08'),
(58, 88, 28, 5, '2024-03-30', '2024-04-09'),
(59, 89, 29, 30, '2024-03-31', '2024-04-10'),
(60, 90, 30, 54, '2024-04-01', '2024-04-11');

CREATE TABLE LibrarySchema.activeOrder
(
	order_id integer PRIMARY KEY,
	bookName varchar(255) NOT NULL,
	autorSurname varchar(30) NOT NULL,
	autorName varchar(30) NOT NULL,
	autorPatronimic varchar(30),
	person_id integer REFERENCES  LibrarySchema.libraryCard(person_id) on DELETE RESTRICT on UPDATE CASCADE
);

CREATE OR REPLACE VIEW LibrarySchema.UserView AS
SELECT bookName, autorSurname, autorName, autorPatronimic, summary FROM LibrarySchema.book
WHERE isGiven = false;

CREATE OR REPLACE FUNCTION LibrarySchema.bookArchive_fun() RETURNS TRIGGER AS $$
DECLARE book_id_new integer;
BEGIN
book_id_new := (SELECT COALESCE(MAX(book_id)+1, 0) FROM LibrarySchema.bookArchive);
INSERT INTO LibrarySchema.bookArchive (book_id, bookName, AutorSurname, AutorName, AutorPatronimic, summary)
VALUES(book_id_new, OLD.bookName, OLD.AutorSurname, OLD.AutorName, OLD.AutorPatronimic, OLD.summary);
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER bookArchiveTrigger 
AFTER DELETE ON LibrarySchema.book
FOR EACH ROW
EXECUTE PROCEDURE LibrarySchema.bookArchive_fun();

CREATE OR REPLACE FUNCTION LibrarySchema.libraryCardArchive_fun() RETURNS TRIGGER AS $$
DECLARE person_id_new integer;
BEGIN
person_id_new := (SELECT COALESCE(MAX(person_id)+1, 0) FROM LibrarySchema.libraryCardArchive);
INSERT INTO LibrarySchema.libraryCardArchive (person_id, persSurname, persName, persPatronimic)
VALUES(person_id_new, OLD.persSurname, OLD.persName, OLD.persPatronimic);
RETURN OLD;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE TRIGGER personArchiveTrigger 
AFTER DELETE ON LibrarySchema.libraryCard
FOR EACH ROW
EXECUTE PROCEDURE LibrarySchema.libraryCardArchive_fun();

/*DROP TABLE LibrarySchema.activeOrder, LibrarySchema.book, LibrarySchema.bookArchive, LibrarySchema.libraryCard,
LibrarySchema.libraryCardArchive, LibrarySchema.givenBackBook, LibrarySchema.givenBook, LibrarySchema.place CASCADE;*/