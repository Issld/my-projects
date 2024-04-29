<?php
include('database_connection.php');

$query = "SELECT id, surname, name, patronymic, bday, login, phone, mail FROM user_table 
INNER JOIN login_table ON user_table.id = login_table.user_id";
$statement = $connection->prepare($query);
$statement->execute();
$result = $statement->fetchAll(PDO::FETCH_ASSOC);

echo json_encode($result);
?>