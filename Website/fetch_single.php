<?php
include('database_connection.php');

if(isset($_GET['user_id'])) {
    $query = "SELECT id, surname, name, patronymic, bday, login, phone, mail FROM user_table INNER JOIN login_table ON user_table.id = login_table.user_id WHERE id = :id";
    $statement = $connection->prepare($query);
    $statement->execute(
        array(
            ':id' => $_GET['user_id']
        )
    );
    echo json_encode($statement->fetch(PDO::FETCH_ASSOC));
}
?>