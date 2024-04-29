<?php
include('database_connection.php');

if($_POST["operation"] == "Add") {
    if (isset($_POST['surname']) && isset($_POST['name']) && isset($_POST['login'])) {
        $query = "INSERT INTO user_table (surname, name, patronymic, bday) VALUES (:surname, :name, :patronymic, :bday)";
        $statement = $connection->prepare($query);
        $statement->execute(
            array(
                ':surname' => $_POST['surname'],
                ':name' => $_POST['name'],
                ':patronymic' => $_POST['patronymic'],
                ':bday' => $_POST['bday']
            )
        );
        $query = "SELECT LAST_INSERT_ID()";
        $statement = $connection->prepare($query);
        $statement->execute();
        $id_value = $statement->fetchColumn();
        echo $id_value;
        $query = "INSERT INTO login_table (login, user_id, phone, mail) VALUES (:login, :user_id, :phone, :mail)";
        $statement = $connection->prepare($query);
        $statement->execute(
            array(
                ':login' => $_POST['login'],
                ':phone' => $_POST['phone'],
                ':mail' => $_POST['mail'],
                ':user_id' => $id_value
            )
        );
    }
}

else if($_POST["operation"] == "Update") {
    if (isset($_POST['surname']) && isset($_POST['name']) && isset($_POST['login'])) {
        $query = "UPDATE user_table SET surname = :surname, name = :name, patronymic = :patronymic, bday = :bday WHERE id = :id";
        $statement = $connection->prepare($query);
        $statement->execute(
            array(
                ':surname' => $_POST['surname'],
                ':name' => $_POST['name'],
                ':patronymic' => $_POST['patronymic'],
                ':bday' => $_POST['bday'],
                ':id' => $_POST['user_id']
            )
        );
        $query = "UPDATE login_table SET login = :login, phone = :phone, mail = :mail WHERE user_id = :id";
        $statement = $connection->prepare($query);
        $statement->execute(
            array(
                ':login' => $_POST['login'],
                ':phone' => $_POST['phone'],
                ':mail' => $_POST['mail'],
                ':id' => $_POST['user_id']
            )
        );
    }
}
?>


