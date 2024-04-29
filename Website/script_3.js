function listWorkDelete(list) {
    if (list) {
        document.addEventListener("keydown", function (event) {
            if (event.key === "Delete") {
                let index = prompt("Введите номер элемента для удаления:");
                if (!isNaN(index)) {
                    list.removeChild(list.children[index - 1]);
                } else {
                    alert("Пожалуйста, введите корректный номер элемента.");
                }
            }
        });
    } else {
        console.log("Список с идентификатором 'myList' не найден.");
    }
}

listWorkDelete(document.getElementById("myList"))

function listWorkAdd(list) {
    if (list) {
        document.addEventListener("keydown", function (event) {
        if (event.key === "Insert") {
            let newItem = prompt("Введите текст нового элемента:");
            let li = document.createElement("li");
            li.textContent = newItem;
            list.appendChild(li);
        }
        });
    } else {
        console.log("Список с идентификатором 'myList' не найден.");
    }
}

listWorkAdd(document.getElementById("myList"))
