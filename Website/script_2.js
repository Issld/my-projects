function addRow(table) {
    if (table) {
        document.addEventListener("keydown", function (event) {
            if (event.key === "Enter") {
                var data1 = prompt("Введите данные для первой ячейки:");
                var newRow = table.insertRow();
                var cell1 = newRow.insertCell();
                cell1.textContent = data1;
                var data2 = prompt("Введите данные для второй ячейки:");
                var cell2 = newRow.insertCell();
                cell2.textContent = data2;
                var data3 = prompt("Введите данные для третьей ячейки:");
                var cell3 = newRow.insertCell();
                cell3.textContent = data3;
                var data4 = prompt("Введите данные для четвертой ячейки:");
                var cell4 = newRow.insertCell();
                cell4.textContent = data4;
                newRow = table.insertRow();
            }
        });
    } else {
        console.log("Таблица с идентификатором 'myTable' не найдена.");
    }
}

addRow(document.getElementById("myTable"))
function changeElemColor(table) {
    if (table) {
        table.addEventListener("click", function (event) {
            var targetCell = event.target;
            document.addEventListener("keydown", function (event) {
                if (event.key === "c") {
                    targetCell.style.backgroundColor = "green";
                }
            });
        });
    } else {
        console.log("Таблица с идентификатором 'myTable' не найдена.");
    }
}

changeElemColor(document.getElementById("myTable"))
function changeElemSize(table) {
    if (table) {
        table.addEventListener("click", function (event) {
            var targetCell = event.target;
            document.addEventListener("keydown", function (event) {
                if (event.key === "s") {
                    targetCell.style.width = "150px";
                    targetCell.style.height = "50px";
                }
            });
        });
    } else {
        console.log("Таблица с идентификатором 'myTable' не найдена.");
    }
}

changeElemSize(document.getElementById("myTable"))
