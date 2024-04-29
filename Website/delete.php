<?php
include('database_connection.php');

if(isset($_POST['user_id'])) {
    $query = "DELETE FROM user_table WHERE id = :id";
    $statement = $connection->prepare($query);
    $statement->execute(
        array(
            ':id' => $_POST['user_id']
        )
    );
    $query = "DELETE FROM login_table WHERE user_id = :id";
    $statement = $connection->prepare($query);
    $statement->execute(
        array(
            ':id' => $_POST['user_id']
        )
    );
}
?>