#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool Check(string x) {
    for (int i = 0; i < x.size(); i++) {
        if (i == 2 || i == 3) {
            if ((int(x[i]) < 48) || (int(x[i]) > 57)) {
                return 0;
            }
        }
        else {
            if ((int(x[i]) < 65) || (int(x[i]) > 90)) {
                return 0;
            }
        }
    }
    return 1;
}

string Input() {
    string x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || Check(x) == 0) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введен ключ некорректного формата! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

bool In(int* a, int x) {
    int n = sizeof(a);
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return 1;
        }
    }
    return 0;
}

int In_menu(int* a) {
    int x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || (In(a, x) == 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введена неизвестная команда! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}


int HashFun(string key, int length) {
    int n = 0;
    for (int i = 0; i < key.size(); i++) {
        n += pow(int(key[i]),2);
    }
    n %= length;
    return n;
}

void Show(string* keys, int* values, int length) {
    for (int i = 0; i < length; i++) {
        if (keys[i] == "DELETED") {
            cout << "DELETED" << endl;
        }
        else {
            cout << keys[i] << ": " << values[i] << endl;
        }
    }
}

bool IsEmpty(string* keys, int length) {
    for (int i = 0; i < length; i++) {
        if (keys[i] == "" || keys[i] == "DELETED") {
            return 0;
        }
    }
    return 1;
}

void Value(int* values, int length) {
    for (int i = 0; i < length; i++) {
        values[i] = i + 1;
    }
}

void Add(string* keys,int* values, int length, int n, string key, int value) {
    bool f = 0;
    for (int k = 1; k < 10; k++) {
        for (int i = n; i < length; i += k) {
            if (keys[i] == "" || keys[i] == "DELETED") {
                keys[i] = key;
                values[i] = value;
                f = 1;
                break;
            }
        }
        if (f == 1) {
            break;
        }
    }
}

bool Delete(string* keys, int* values, int length, string key) {
    bool f = 1;
    int razn = 0;
    int n = HashFun(key, length);
    for (int k = 1; k < 10; k++) {
        for (int i = n; i < length; i += k) {
            if (keys[i] == key) {
                keys[i] = "DELETED";
                cout << keys[i] << endl;
                return 1;
            }
        }
    }
    return 0;
}

bool Search(string* keys, int* values, int length, string key, int* x) {
    int n = HashFun(key, length);
    for (int k = 1; k < 10; k++) {
        for (int i = n; i < length; i += k) {
            if (keys[i] == key) {
                *x = values[i];
                return 1;
            }
            if (keys[i] == "") {
                return 0;
            }
        }
    }
}

int Inf() {
    int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
    cout << "Хотите создать пустую хеш-таблицу, нажмите 1" << endl;
    cout << "Хотите создать заполненную хеш-таблицу, нажмите 2" << endl;
    cout << "Хотите добавить элемент в хеш-таблицу, нажмите 3" << endl;
    cout << "Хотите найти элемент в хеш-таблице, нажмите 4" << endl;
    cout << "Хотите выгрузить данные хеш-функции, нажмите 5" << endl;
    cout << "Хотите удалить элемент из хеш-таблицы, нажмите 6" << endl;
    cout << "Хотите выйти из хеш-таблицы, нажмите 7" << endl;
    return In_menu(a);
}

int main() {
    setlocale(0, "");
    int length = 2000;
    string keys[2000];
    int values[2000];
    int all_hash[2000];
    int n, x, k, value;
    string key = "";
    ofstream fw;
    string s;
    int a[2] = { 1, 2 };
    cout << HashFun("321", 3);
    system("pause");
    do {
        system("cls");
        k = Inf();
        switch (k) {
        case 1:
            for (int i = 0; i < length; i++) {
                keys[i] = "";
                values[i] = 0;
            }
            cout << "Создана хеш-таблица" << endl;
            system("pause");
            break;
        case 2:
            for (int i = 0; i < length; i++) {
                keys[i] = "";
                values[i] = 0;
            }
            key = "";
            for (int i = 0; i < length * 3; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 2 || j == 3) {
                        key += '0' + rand() % ('9' - '0');
                    }
                    else {
                        key += 'A' + rand() % ('Z' - 'A');
                    }
                }
                n = HashFun(key, length);
                Add(keys,values, length, n, key, 1);
                Value(values, length);
                key = "";
            }
            Show(keys, values, length);
            system("pause");
            break;
        case 3:
            if (IsEmpty(keys, length) == 0) {
                cout << "Введите ключ добавляемого элемента: ";
                key = Input();
                cout << "Введите значение добавляемого элемента: ";
                cin >> value;
                n = HashFun(key, length);
                Add(keys, values, length, n, key, value);
                Show(keys, values, length);
            }
            else {
                cout << "Ошибка! Хеш-таблица переполнена" << endl;
            }
            system("pause");
            break;
        case 4:
            cout << "Хотите искать по ключу(1) или по номеру(2): ";
            x = In_menu(a);
            if (x == 1) {
                cout << "Введите ключ: ";
                key = Input();
                if (Search(keys, values, length, key, &x) == 1) {
                    cout << "Ключ соответствует числу: " << x << endl;
                }
                else {
                    cout << "В хеш-таблице нет такого ключа" << endl;
                }
            }
            else {
                cout << "Введите номер: ";
                cin >> x;
                if (keys[x - 1] == "" || x > length || x < 1) {
                    cout << "В хеш-таблице нет элемента с заданным номером" << endl;
                }
                else if (keys[x - 1] == "DELETED") {
                    cout << "Элемент с заданным номером удален" << endl;
                }
                else {
                    cout << "Этому номеру соответствует ключ: " << keys[x - 1] << endl;
                }
            }
            system("pause");
            break;
        case 5:
            for (int i = 0; i < length; i++) {
                all_hash[i] = 0;
            }
            cout << "Введите название файла для сохранения: ";
            cin >> s;
            fw.open(s);
            key = "";
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < 6; j++) {
                    if (j == 2 || j == 3) {
                        key += '0' + rand() % ('9' - '0');
                    }
                    else {
                        key += 'A' + rand() % ('Z' - 'A');
                    }
                }
                all_hash[HashFun(key, length)] ++;
                key = "";
            }
            for (int i = 0; i < length; i++) {
                fw << all_hash[i] << endl; 
            }
            system("pause");
            break;
        case 6:
            cout << "Введите ключ удаляемого элемента: ";
            key = Input();
            if (Delete(keys, values, length, key) == 1) {
                Show(keys, values, length);
            }
            else {
                cout << "В хеш-таблице нет элемента под таким ключем" << endl;
            }
            system("pause");
            break;
        }
    } while (k != 7);
    fw.close();
    return 0;
}