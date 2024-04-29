<?php
include('database_connection.php');

if(isset($_GET['user_id'])) {
    $query = "SELECT * FROM user_table INNER JOIN login_table ON user_table.id = login_table.user_id
    WHERE surname = :surname AND name = :name AND patronymic = :patronymic AND bday = :bday AND login = :login AND phone = :phone AND mail = :mail";
    $statement = $connection->prepare($query);
    $statement->execute(
        array(
            ':surname' => $_GET['surname'],
            ':name' => $_GET['name'],
            ':patronymic' => $_GET['patronymic'],
            ':bday' => $_GET['bday'],
            ':login' => $_GET['login'],
            ':phone' => $_GET['phone'],
            ':mail' => $_GET['mail']
        )
    );
    if($statement->rowCount() == 0) {
        echo "true";
    }
    else{
        echo "false";
    }
}
?>
