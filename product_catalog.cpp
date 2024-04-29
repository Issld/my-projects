/*#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif*/

//Исправить ввод для пробела на getline и запретить _ на вход

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct Price {
    string Tname;
    string Mname;
    int Cost;
    Price* next;
};

bool Check_In(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            return 1;
        }
    }
    return 0;
}

int In_Choice(int a, int b, int c) {
    int x;
    if (a != 1) {
        cin >> x;
        while (cin.fail() || (cin.get() != '\n') || ((x != a) && (x != b) && (x != c) && (x != 9))) {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Введена неизвестная команда! \nПожалуйста, прочтите инструкцию внимательно и повторите ввод: ";
            cin >> x;
        }
    }
    else {
        cin >> x;
        while (cin.fail() || (cin.get() != '\n') || ((x != a) && (x != c) && (x != 9))) {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "Введена неизвестная команда! \nПожалуйста, прочтите инструкцию внимательно и повторите ввод: ";
            cin >> x;
        }
    }
    return x;
}

string In() {
    string x;
    getline(cin, x, '\n'); 
    while (cin.fail() || Check_In(x) == 1) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Ошибка ввода! \nПожалуйста, повторите ввод: ";
        getline(cin, x, '\n');
    }
    return x;
}

bool In_file(string s) {
    try {
        int x = stoi(s);
    }
    catch (exception& ex) {
        return 0;
    }
    return 1;
}

string In_Name() {
    string x;
    getline(cin, x, '\n');
    int n = x.length();
    if (n <= 4) {
        n = 5;
    }
    while (cin.fail() || (x.substr(n - 4, 4) != ".txt")) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введено название с указанием некорректного формата или без него вовсе! \nПожалуйста, повторите ввод: ";
        getline(cin, x, '\n');
        n = x.length();
        if (n <= 4) {
            n = 5;
        }
    }
    return x;
}

int In_Cost() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n')) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Ошибка, стоимость должна быть обрабатываемым числом! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

int In_Sort(int a, int b, int c) {
    int x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || ((x != a) && (x != b) && (x != c))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введена неизвестная команда! \nПожалуйста, прочтите инструкцию внимательно и повторите ввод: ";
        cin >> x;
    }
    return x;
}

int In_Inp(int a, int b) {
    int x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || ((x != a) && (x != b))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введена неизвестная команда! \nПожалуйста, прочтите инструкцию внимательно и повторите ввод: ";
        cin >> x;
    }
    return x;
}

bool Check(Price* head, string t, string m, int c) {
    Price* cur = head;
    bool f = 0;
    while (cur != NULL) {
        if (cur->Mname == m) {
            if (cur->Tname == t) {
                if (cur->Cost == c) {
                    f = 1;
                    break;
                }

            }
        }
        cur = cur->next;
    }
    return f;
}

void Add(Price** head, string valN, string valM, int valC) {
    Price* cur = *head;
    Price* p = new Price;
    p->Tname = valN;
    p->Mname = valM;
    p->Cost = valC;
    if (cur == NULL) {
        p->next = NULL;
        *head = p;
    }
    else {
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = p;
        p->next = NULL;
    }
}

void Show(Price* head) {
    setlocale(0, "");
    Price* p = head;
    while (p != NULL) {
        cout << p->Mname << " " << p->Tname << " " << p->Cost;
        p = p->next;
        if (p != NULL) {
            cout << endl;
        }
    }
}

void DeleteAll(Price** head) {
    Price* cur = NULL;
    if (*head != NULL) {
        while ((*head)->next != NULL) {
            cur = *head;
            *head = (*head)->next;
            delete cur;
        }
    }
    delete* head;
}

void Delete(Price** head, Price** o) {
    Price* cur = *head;
    Price* c = *o;
    if ((cur->Mname == c->Mname) || (cur->Tname == c->Tname) || (cur->Cost == c->Cost)) {
        *head = cur->next;
    }
    else {
        while ((cur->next->Mname != c->Mname) || (cur->next->Tname != c->Tname) || (cur->next->Cost != c->Cost)) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
}

void Save(Price* head, string name) {
    Price* p = head;
    ofstream fw;
    fw.open(name);
    while (p != NULL) {
        fw << p->Mname << "/" << p->Tname << "/" << p->Cost << endl;
        p = p->next;
    }
}

bool Open(Price* head, string name) {
    ifstream fr;
    string n = name;
    fr.open(name);
    bool f = 1;
    string st, sm, sc;
    int c;
    if (!fr.is_open()) {
        f = 0;
    }
    else {
        while (!fr.eof()) {
            getline(fr, sm, '/');
            getline(fr, st, '/');
            getline(fr, sc, '\n');
            if (In_file(sc)) {
                c = stoi(sc);
                if (Check(head, st, sm, c) != 1) {
                    Add(&head, st, sm, c);
                }
            }
        }
    }
    return f;
}

void Change(Price** head, Price** o, string valuet, string valuem, int valuec) {
    Price* cur = *head;
    Price* c = *o;
    if ((cur->Mname == c->Mname) || (cur->Tname == c->Tname) || (cur->Cost == c->Cost)) {
        cur->Mname = valuem;
        cur->Tname = valuet;
        cur->Cost = valuec;
    }
    else {
        while ((cur->next->Mname != c->Mname) || (cur->next->Tname != c->Tname) || (cur->next->Cost != c->Cost)) {
            cur = cur->next;
        }
        cur->next->Mname = valuem;
        cur->next->Tname = valuet;
        cur->next->Cost = valuec;
    }
}

Price* Sort(Price* head, int n) {
    Price* counter = head;
    Price* cur, * cur_sort, * prev;
    Price* sort = NULL;
    switch (n) {
    case(1):
        while (counter != NULL) {
            cur = counter;
            cur_sort = sort;
            prev = NULL;
            counter = counter->next;
            while ((cur_sort != NULL) && (cur->Mname > cur_sort->Mname)) {
                prev = cur_sort;
                cur_sort = cur_sort->next;
            }
            if (prev == NULL) {
                cur->next = sort;
                sort = cur;
            }
            else {
                cur->next = cur_sort;
                prev->next = cur;
            }
        }
        break;
    case(2):
        while (counter != NULL) {
            cur = counter;
            cur_sort = sort;
            prev = NULL;
            counter = counter->next;
            while ((cur_sort != NULL) && (cur->Tname > cur_sort->Tname)) {
                prev = cur_sort;
                cur_sort = cur_sort->next;
            }
            if (prev == NULL) {
                cur->next = sort;
                sort = cur;
            }
            else {
                cur->next = cur_sort;
                prev->next = cur;
            }
        }
        break;
    case(3):
        while (counter != NULL) {
            cur = counter;
            cur_sort = sort;
            prev = NULL;
            counter = counter->next;
            while ((cur_sort != NULL) && (cur->Cost > cur_sort->Cost)) {
                prev = cur_sort;
                cur_sort = cur_sort->next;
            }
            if (prev == NULL) {
                cur->next = sort;
                sort = cur;
            }
            else {
                cur->next = cur_sort;
                prev->next = cur;
            }
        }
        break;
    }
    return sort;
}

Price* Search(Price** head, string value, int n) {
    Price* cur = *head;
    Price* c = NULL;
    switch (n) {
    case(1):
        while (cur != NULL) {
            if (cur->Mname == value) {
                Add(&c, cur->Tname, cur->Mname, cur->Cost);
            }
            cur = cur->next;
        }
        break;
    case(2):
        while (cur != NULL) {
            if (cur->Tname == value) {
                Add(&c, cur->Tname, cur->Mname, cur->Cost);
            }
            cur = cur->next;
        }
        break;
    }
    return c;
}

Price* Search(Price** head, int value) {
    Price* cur = *head;
    Price* c = NULL;
    while (cur != NULL) {
        if (cur->Cost == value) {
            Add(&c, cur->Tname, cur->Mname, cur->Cost);
        }
        cur = cur->next;
    }
    return c;
}

bool Input(Price* head, string* m, string* t, int* c) {
    Price* cur = head;
    bool f = 0;
    while (cur != NULL) {
        if (cur->Mname == *m) {
            if (cur->Tname == *t) {
                if (cur->Cost == *c) {
                    f = 1;
                    break;
                }

            }
        }
        if (cur->next == NULL) {
            break;
        }
        else {
            cur = cur->next;
        }
    }
    if (f == 1) {
        cout << "Товар с такими параметрами уже есть! Повторите ввод" << endl;
        cout << "Введите название магазина: ";
        *m = In();
        cout << "Введите название товара: ";
        *t = In();
        cout << "Введите стоимость товара: ";
        *c = In_Cost();
    }
    return f;
}

int Lengh(Price* head) {
    Price* p = head;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->next;
    }
    return n;
}

int Choice(int l) {
    int j = 0, i = 1;
    int a, b, c;
    if (l == 0) {
        cout << "Приветствуем вас в сервисной поддержке магазинов нашего города ";
        Sleep(3000);
    }
    while ((j != i) && (i != 9)) {
        system("cls");
        if (i < j) {
            j = i;
        }
        switch (i) {
        case (0):
            cout << "Ожидайте, вам ответит первый освободившийся оператор" << endl;
            Sleep(5000);
            cout << "К сожалению все операторы сейчас заняты" << endl;
            cout << "Хотите просмотреть все варианты еще раз, нажмите 1" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 1;
            b = 0;
            c = 9;
            break;
        case (1):
            cout << "Хотите добавить товар, нажмите 1" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 2" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 1;
            b = 0;
            c = 2;
            break;
        case (2):
            cout << "Хотите изменить информацию о товаре, нажмите 2" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 1" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 3" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 2;
            b = 1;
            c = 3;
            break;
        case(3):
            cout << "Хотите удалить товар, нажмите 3" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 2" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 4" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 3;
            b = 2;
            c = 4;
            break;
        case (4):
            cout << "Хотите найтить товар, нажмите 4" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 3" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 5" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 4;
            b = 3;
            c = 5;
            break;
        case (5):
            cout << "Хотите вывести информацию о всех сотрудничающих с нами магазинах и их товарах, нажмите 5" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 4" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 6" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 5;
            b = 4;
            c = 6;
            break;
        case (6):
            cout << "Хотите отсортировать всю информацию, нажмите 6" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 5" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 7" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 6;
            b = 5;
            c = 7;
            break;
        case (7):
            cout << "Хотите сохранить всю информацию, нажмите 7" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 6" << endl;
            cout << "Хотите перейти к следующему пункту, нажмите 8" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 7;
            b = 6;
            c = 8;
            break;
        case (8):
            cout << "Хотите обратится к новым базам, нажмите 8" << endl;
            cout << "Хотите перейти к предыдующему пункту, нажмите 7" << endl;
            cout << "Хотите обсудить свой вопрос с оператором нажмите 0" << endl;
            cout << "Хотите завершить сеанс нажмите 9" << endl;
            a = 8;
            b = 7;
            c = 0;
            break;
        }
        i = In_Choice(a, b, c);
        if (i == 9) {
            break;
        }
        j++;
        if (i == 0) {
            j = 1;
        }
    }
    return i;
}

int main() {
    setlocale(0, "");
    {
        Price* list = NULL;
        Price* o = NULL;
        Price* d = NULL;
        ifstream fr;
        fr.open("Test.txt");
        string st, sm, sc, oldSt, pst, psm, psc;
        int c = 0, oldV = 0, i = -1, x = -1, l = 0, n = 0, p = 0;
        bool f = 1, op = 1;
        while (!fr.eof()) {
            getline(fr, sm, '/');
            getline(fr, st, '/');
            getline(fr, sc, '\n');
            c = stoi(sc);
            Add(&list, st, sm, c);
        }
        Sort(list, 1);
        system("pause");
        while (i != 9) {
            i = Choice(l);
            switch (i) {
            case(1):
                cout << "Введите название магазина: ";
                sm = In();
                cout << "Введите название товара: ";
                st = In();
                cout << "Введите стоимость товара: ";
                c = In_Cost();
                f = 1;
                while (f != 0) {
                    f = Input(list, &sm, &st, &c);
                }
                Add(&list, st, sm, c);
                Show(list);
                system("pause");
                //Sleep(5000);
                break;
            case(2):
                cout << "Изменение происходит по названию магазина(1), товара(2), стоимости(3): ";
                n = In_Sort(1, 2, 3);
                switch (n) {
                case(1):
                    cout << "Введите название магазина: ";
                    oldSt = In();
                    break;
                case(2):
                    cout << "Введите название товара: ";
                    oldSt = In();
                    break;
                case(3):
                    cout << "Введите стоимость товара: ";
                    oldV = In_Cost();
                    break;
                }
                cout << "Введите новое название магазина: ";
                sm = In();
                cout << "Введите новое название товара: ";
                st = In();
                cout << "Введите новую стоимость товара: ";
                c = In_Cost();
                f = 1;
                while (f != 0) {
                    f = Input(list, &sm, &st, &c);
                }
                if (n == 3) {
                    o = Search(&list, oldV);
                }
                else {
                    o = Search(&list, oldSt, n);
                }
                p = Lengh(o);
                if (p == 0) {
                    cout << "Нет подходящего элемента!" << endl;
                }
                else if (p == 1) {
                    cout << "После изменения получено:" << endl;
                    Change(&list, &o, st, sm, c);
                    Show(list);
                }
                else {
                    cout << "Найдено несколько элементов: " << endl;
                    Show(o);
                    switch (n) {
                    case(1):
                        cout << "\nУточнение изменения происходит по: названию товара(2), стоимости(3): ";
                        n = In_Inp(2, 3);
                        break;
                    case(2):
                        cout << "\nУточнение изменения происходит по: названию магазина(1), стоимости(3): ";
                        n = In_Inp(1, 3);
                        break;
                    case(3):
                        cout << "\nУточнение изменения происходит по: названию магазина(1), названию товара(2): ";
                        n = In_Inp(1, 2);
                        break;
                    }
                    cout << "Введите уточняющее значение: ";
                    if (n == 3) {
                        oldV = In_Cost();
                        d = Search(&o, oldV);
                    }
                    else {
                        oldSt = In();
                        d = Search(&o, oldSt, n);
                    }
                    p = Lengh(d);
                    if (p == 0) {
                        cout << "Нет подходящего элемента!" << endl;
                    }
                    else {
                        cout << "После изменения получено:" << endl;
                        Change(&list, &d, st, sm, c);
                        Show(list);
                    }
                }
                system("pause");
                //Sleep(5000);
                break;
            case(3):
                cout << "Удаление происходит по названию магазина(1), товара(2), стоимости(3): ";
                n = In_Sort(1, 2, 3);
                switch (n) {
                case(1):
                    cout << "Введите название магазина: ";
                    st = In();
                    break;
                case(2):
                    cout << "Введите название товара: ";
                    st = In();
                    break;
                case(3):
                    cout << "Введите стоимость товара: ";
                    c = In_Cost();
                    break;
                }
                if (n == 3) {
                    o = Search(&list, c);
                }
                else {
                    o = Search(&list, st, n);
                }
                p = Lengh(o);
                if (p == 0) {
                    cout << "Нет подходящего элемента!" << endl;
                }
                else if (p == 1) {
                    cout << "После удаления получено:" << endl;
                    Delete(&list, &o);
                    Show(list);
                }
                else {
                    cout << "Найдено несколько элементов: " << endl;
                    Show(o);
                    switch (n) {
                    case(1):
                        cout << "\nУточнение удаления происходит по: названию товара(2), стоимости(3): ";
                        n = In_Inp(2, 3);
                        break;
                    case(2):
                        cout << "\nУточнение удаления происходит по: названию магазина(1), стоимости(3): ";
                        n = In_Inp(1, 3);
                        break;
                    case(3):
                        cout << "\nУточнение удаления происходит по: названию магазина(1), названию товара(2): ";
                        n = In_Inp(1, 2);
                        break;
                    }
                    cout << "Введите уточняющее значение: ";
                    if (n == 3) {
                        oldV = In_Cost();
                        d = Search(&o, oldV);
                    }
                    else {
                        oldSt = In();
                        d = Search(&o, oldSt, n);
                    }
                    p = Lengh(d);
                    if (p == 0) {
                        cout << "Нет подходящего элемента!" << endl;
                    }
                    else {
                        cout << "После удаления получено:" << endl;
                        Delete(&list, &d);
                        Show(list);
                    }
                }
                system("pause");
                //Sleep(5000);
                break;
            case(4):
                cout << "Поиск происходит по названию магазина(1), товара(2), стоимости(3): ";
                n = In_Sort(1, 2, 3);
                switch (n) {
                case(1):
                    cout << "Введите название магазина: ";
                    st = In();
                    break;
                case(2):
                    cout << "Введите название товара: ";
                    st = In();
                    break;
                case(3):
                    cout << "Введите стоимость товара: ";
                    c = In_Cost();
                    break;
                }
                if (n == 3) {
                    o = Search(&list, c);
                }
                else {
                    o = Search(&list, st, n);
                }
                p = Lengh(o);
                if (p == 0) {
                    cout << "Нет подходящего элемента!" << endl;
                }
                else if (p == 1) {
                    cout << "Искомый элемент: ";
                    Show(o);
                }
                else {
                    cout << "Найдено несколько элементов: " << endl;
                    Show(o);
                    switch (n) {
                    case(1):
                        cout << "\nУточнение поиска происходит по: названию товара(2), стоимости(3): ";
                        n = In_Inp(2, 3);
                        break;
                    case(2):
                        cout << "\nУточнение поиска происходит по: названию магазина(1), стоимости(3): ";
                        n = In_Inp(1, 3);
                        break;
                    case(3):
                        cout << "\nУточнение поиска происходит по: названию магазина(1), названию товара(2): ";
                        n = In_Inp(1, 2);
                        break;
                    }
                    cout << "Введите уточняющее значение: ";
                    if (n == 3) {
                        oldV = In_Cost();
                        d = Search(&o, oldV);
                    }
                    else {
                        oldSt = In();
                        d = Search(&o, oldSt, n);
                    }
                    p = Lengh(d);
                    if (p == 0) {
                        cout << "Нет подходящего элемента!" << endl;
                    }
                    else {
                        cout << "Искомый элемент: ";
                        Show(d);
                    }
                }
                system("pause");
                //Sleep(5000);
                break;
            case(5):
                cout << "Вот весь список товаров:" << endl;
                Show(list);
                system("pause");
                //Sleep(5000);
                break;
            case(6):
                cout << "Сортировка происходит по названию магазина(1), товара(2), стоимости(3) : ";
                x = In_Sort(1, 2, 3);
                list = Sort(list, x);
                Show(list);
                system("pause");
                //Sleep(5000);
                break;
            case(7):
                cout << "Введите имя под которым хотите сохранить информацию (не забудте указать тип файла (.txt): ";
                st = In_Name();
                Save(list, st);
                cout << "Успешно сохранено" << endl;
                system("pause");
                //Sleep(5000);
                break;
            case(8):
                cout << "Введите имя файла загружаемой информации (не забудте указать тип файла (.txt): ";
                st = In_Name();
                cout << "Выберете хотите ли вы добавить данные из файла(1) или полность обновить базу(2): ";
                c = In_Inp(1, 2);
                if (c == 1) {
                    op = Open(list, st);
                }
                else {
                    DeleteAll(&list);
                    Price* list = NULL;
                    op = Open(list, st);
                }
                if (op == 1) {
                    Show(list);
                    system("pause");
                    //Sleep(5000);
                }
                else {
                    cout << "База данных с таким именем не найдена!" << endl;
                    system("pause");
                    //Sleep(5000);
                }
                break;
            case (9):
                cout << "Благодарим за использование нашего сервиса! Удачного дня!" << endl;
                break;
            }
            l = 1;
        }
        Save(list, "Save after exit.txt");
        DeleteAll(&list);
        DeleteAll(&o);
        DeleteAll(&d);
        fr.close();
    }
    /*_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();*/
    return 0;
}