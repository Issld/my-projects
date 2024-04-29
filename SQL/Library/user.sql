--Создание роли и пользователя Пользователь бд
CREATE ROLE LibraryUserRole; --создание роли пользователь библиотеки
GRANT USAGE ON SCHEMA LibrarySchema TO LibraryUserRole; --предоставление созданной роли прав использования схемы LibrarySchema
GRANT SELECT ON LibrarySchema.UserView TO LibraryUserRole; --предоставление созданной роли прав чтения данных из представления UserView
GRANT INSERT ON LibrarySchema.ActiveOrder TO LibraryUserRole; --предоставление созданной роли прав записывать данные в таблицу ActiveOrder
CREATE USER LibraryUser WITH PASSWORD '123456'; --создание пользователя для базы данных
GRANT LibraryUserRole TO LibraryUser; --назначение пользователя LibraryUser на роль LibraryUserRole

--Создание роли и пользователя Админ бд
CREATE ROLE LibraryAdminRole; --создание роли администратор библиотеки
GRANT USAGE ON SCHEMA LibrarySchema TO LibraryAdminRole; --предоставление созданной роли прав использования схемы LibrarySchema
GRANT ALL PRIVELEGES ON ALL TABLES IN SCHEMA LibrarySchema TO LibraryAdminRole; --предоставление созданной роли всех прав для всех таблиц схемы LibrarySchema
CREATE USER LibraryAdmin WITH PASSWORD '1234567'; --создание пользователя для базы данных
GRANT LibraryAdminRole TO LibraryAdmin; --назначение пользователя LibraryAdmin на роль LibraryAdminRole