#!D:/Python/python.exe
#coding: utf-8

import cgi, datetime
form = cgi.FieldStorage() # извлечь данные из формы
print ("Content-type: text/html; charset=utf-8\n") # плюс пустая строка
html = """
<!DOCTYPE html>
<html lang="ru">
<head>
<meta charset="UTF-8">
<meta name="author" content="Иван Сидоров">
<meta name="keywords" content="BigData">
<TITLE>Результат</TITLE>
<link rel="stylesheet" href="style_3.css">
</head>
<H1>Анкета пользователя</H1> <HR>
<H4>Фамилия пользователя: %(surname)s</H4>
<H4>Имя пользователя: %(name)s</H4>
<H4>Отчество пользователя: %(patr)s </H4>
<H4>Планы дальнейшего использования: %(worktype)s</H4>
<H4>Используемые технологии: %(technology)s</H4>
<H4>Используемое ПО: <img src="%(software)s" width="15%%" height="auto"></H4>
<H4>Информация о учащемся: %(role)s</H4>
<H4>Комментарий:</H4>
<P>%(comment)s</P>
<HR>"""
data = {}
file = open('responses.txt', 'a')
now = datetime.datetime.now()
file.write("Запись от: " + now.strftime("%d/%m/%Y %H:%M:%S") +'\n')
for field in ('surname', 'name', 'patr', 'worktype', 'technology', 'software', 'role', 'comment'):
    if not field in form:
        data[field] = '(unknown)'
        value = 'Не заполнено'
    else:
        if not isinstance(form[field], list):
            data[field] = form[field].value
            value = form.getfirst(field)
        elif field == 'software':
            value = 'image'
            data[field] = form[field].value
        else:
            values = [x.value for x in form[field]]
            data[field] = ', '.join(values)
            value = form.getlist(field)
            value = ', '.join(value)
        file.write(f"{value}")
    file.write('\n')
html += """
<script>
    setTimeout(function() {
      window.location.href = "forma.html";
    }, 5000); // 5000 milliseconds = 5 seconds
  </script>
</body>
</html>
"""
print(html % data)
file.write('\n')