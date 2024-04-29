<!doctype html>
<head>
    <title>Благодарность</title>
    <link rel="stylesheet" type="text/css" href="styleOutput.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <link rel="stylesheet" href="tableStyle.css">
    <style>
        body {
            background-color: #f9e8d1;
        }
    </style>
</head>
<body>
<div class="content">
    <h1>Благодарим наших самых преданных читателей:</h1>
    <table id="user_table" class="custom-table">
        <thead bgcolor="#6cd8dc">
        <tr class="table-primary">
            <th width="6%">Id</th>
            <th width="12%">Фамилия</th>
            <th width="12%">Имя</th>
            <th width="12%">Отчество</th>
            <th width="12%">День рождения</th>
            <th width="12%">Логин</th>
            <th width="12%">Телефон</th>
            <th width="12%">Почта</th>
            <th scope="col" width="5%"></th>
            <th scope="col" width="5%"></th>
        </tr>
        </thead>
        <tbody id="table_body"></tbody>
    </table>
    </br>
    <div align="right">
        <button type="button" id="add_button" data-toggle="modal" data-target="#userModal" class="btn btn-success btn-lg">Add</button>
    </div>
</div>
<hr>
<div class="links">
    <a href="index.html">Основные сведения</a>
    <a href="second.html">История</a>
    <a href="third.html">Источники</a>
    <a href="forma.html">Опрос</a>
    <a href="main.php">Благодарность</a>
</div>
<hr>
<div id="footer" align="center">Сидоров Иван, 4131</div>
</body>
</html>

<div id="userModal" class="modal fade">
    <div class="modal-dialog">
        <form method="post" id="user_form" enctype="multipart/form-data">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal">&times;</button>
                    <h4 class="modal-title">Добавление записи</h4>
                </div>
                <div class="modal-body">
                    <label>Введите фамилию</label>
                    <input type="text" name="surname" id="surname" class="form-control" />
                    <br />
                    <label>Введите имя</label>
                    <input type="text" name="name" id="name" class="form-control" />
                    <br />
                    <label>Введите отчество</label>
                    <input type="text" name="patronymic" id="patronymic" class="form-control" />
                    <br />
                    <label>Введите день рождения</label>
                    <input type="text" name="bday" id="bday" class="form-control" />
                    <br />
                    <label>Введите логин</label>
                    <input type="text" name="login" id="login" class="form-control" />
                    <br />
                    <label>Введите телефон</label>
                    <input type="text" name="phone" id="phone" class="form-control" />
                    <br />
                    <label>Введите почту</label>
                    <input type="text" name="mail" id="mail" class="form-control" />
                    <br />
                </div>
                <div class="modal-footer">
                    <input type="hidden" name="user_id" id="user_id" />
                    <input type="hidden" name="operation" id="operation" />
                    <input type="submit" name="action" id="action" class="btn btn-primary" value="action" />
                    <button type="button" class="btn btn-danger" data-dismiss="modal">Close</button>
                </div>
            </div>
        </form>
    </div>
</div>

<script type="text/javascript" language="javascript">
    $(document).ready(function() {
        function loadData() {
            $.ajax({
                url: 'fetch.php',
                method: 'GET',
                dataType: 'json',
                success: function (data) {
                    var html = '';
                    $.each(data, function(index, item) {
                        html += '<tr>';
                        html += '<td>' + item.id + '</td>';
                        html += '<td>' + item.surname + '</td>';
                        html += '<td>' + item.name + '</td>';
                        html += '<td>' + item.patronymic + '</td>';
                        html += '<td>' + item.bday + '</td>';
                        html += '<td>' + item.login + '</td>';
                        html += '<td>' + item.phone + '</td>';
                        html += '<td>' + item.mail + '</td>';
                        html += '<td><button type="button" name="update" id="' + item.id + '" class="btn btn-primary btn-sm update">Edit</button></td>';
                        html += '<td><button type="button" name="delete" id="' + item.id + '" class="btn btn-danger btn-sm delete">Delete</button></td>';
                        html += '</tr>';
                    });
                    $('#table_body').html(html);
                }
            });
        }
        loadData();

        $('#add_button').click(function () {
            $('#user_form')[0].reset();
            $('.modal-title').text("Добавление записи");
            $('#action').val("Add");
            $('#operation').val("Add");
        });

        $('#user_form').submit(function(event){
            event.preventDefault();
            var formData = $(this).serialize();
            var xhr = new XMLHttpRequest();
            xhr.open('GET', 'check.php?' + formData);
            xhr.onreadystatechange = function() {
                if (xhr.readyState === XMLHttpRequest.DONE) {
                    if (xhr.status === 200) {
                        var flag = xhr.responseText;
                        if (flag === 'true') {
                            $.ajax({
                                url: 'insert.php',
                                method: 'POST',
                                data: formData,
                                success: function (data) {
                                    console.log(data);
                                    loadData();
                                }
                            });
                            $('#user_form')[0].reset();
                            $('#userModal').modal('hide');
                        }
                        else{
                            alert("Такая запись уже существует!");
                        }
                    }
                    else{
                        console.log("Error");
                    }
                }
            };
            xhr.send();
             /*$.ajax({
                url: 'check.php',
                method: 'GET',
                data: formData,
                success: function (flag) {
                    console.log(flag);
                    if (flag === 'true') {
                        $.ajax({
                            url: 'insert.php',
                            method: 'POST',
                            data: formData,
                            success: function (data) {
                                console.log(data);
                                loadData();
                            }
                        });
                        $('#user_form')[0].reset();
                        $('#userModal').modal('hide');
                    }
                    else{
                        alert("Такая запись уже существует!");
                    }
                }*/
            //});

        });

        $(document).on('click', '.update', function(){
            var user_id = $(this).attr('id');
            $.ajax({
                url: 'fetch_single.php',
                method: 'GET',
                data: {user_id: user_id},
                dataType: 'json',
                success: function(data) {
                    $('#surname').val(data.surname);
                    $('#name').val(data.name);
                    $('#patronymic').val(data.patronymic);
                    $('#bday').val(data.bday);
                    $('#login').val(data.login);
                    $('#phone').val(data.phone);
                    $('#mail').val(data.mail);
                    $('#user_id').val(user_id);
                    $('.modal-title').text("Изменение записи");
                    $('#action').val("Save");
                    $('#operation').val("Update");
                    $('#userModal').modal('show');
                }
            });
        });

        $(document).on('click', '.delete', function(){
            if(confirm("Вы уверены, что хотите удалить запись?")) {
                var user_id = $(this).attr('id');
                $.ajax({
                    url: 'delete.php',
                    method: 'POST',
                    data: {user_id: user_id},
                    success: function(data) {
                        loadData();
                    }
                });
            }
        });
    });

</script>