#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

struct Passenger {
    string passport;
    string place;
    string date_give;
    string fio;
    string date_birth;
    Passenger* next;
};

struct Flight {
    string number;
    string name;
    string out;
    string in;
    string date;
    string time;
    int sit;
    int sit_free;
    int high;
    Flight* left;
    Flight* right;
};

struct Ticket {
    string passport;
    string number_flight;
    string number_ticket;
    Ticket* prew;
    Ticket* next;
};

bool In(vector <int> a, int x) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            return 1;
        }
    }
    return 0;
}

int In_menu(vector <int> a) {
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

bool IsIn(string a, char b) {
    for (int i = 0; i < a.size(); i++) {
        if (b == a[i]) {
            return 1;
        }
    }
    return 0;
}

bool In_mask_passport(string x) {
    string a = "0123456789";
    if (x.size() != 11) {
        return 0;
    }
    for (int i = 0; i < 11; i++) {
        if (i == 4) {
            if (x[i] != '-') {
                return 0;
            }
        }
        else {
            if (!IsIn(a, x[i])) {
                return 0;
            }
        }
    }
    return 1;
}

bool In_mask_number_flight(string x) {
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string b = "0123456789";
    if (x.size() != 7) {
        return 0;
    }
    for (int i = 0; i < 7; i++) {
        if (i == 3) {
            if (x[i] != '-') {
                return 0;
            }
        }
        else if (i < 3) {
            if (!IsIn(a, x[i])) {
                return 0;
            }
        }
        else {
            if (!IsIn(b, x[i])) {
                return 0;
            }
        }
    }
    return 1;
}

bool In_mask_number_ticket(string x) {
    string a = "0123456789";
    if (x.size() != 9) {
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        if (!IsIn(a, x[i])) {
            return 0;
        }
    }
    return 1;
}

string Mask_passport() {
    string x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || (In_mask_passport(x) == 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Номер пасспорта не соответствует норме! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

string Mask_number_flight() {
    string x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || (In_mask_number_flight(x) == 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Номер авиарейса не соответствует норме! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

string Mask_number_ticket() {
    string x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || (In_mask_number_ticket(x) == 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Номер авиабилета не соответствует норме! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

bool True_date(string birth, string give) {
    if (stoi(give.substr(6,4)) - stoi(birth.substr(6,4)) < 14) {
        return 0;
    }
    else if (stoi(give.substr(6, 4)) - stoi(birth.substr(6, 4)) == 14) {
        if (stoi(give.substr(3, 2)) - stoi(birth.substr(3, 2)) < 0) {
            return 0;
        }
        else if (stoi(give.substr(3, 2)) - stoi(birth.substr(3, 2)) == 0) {
            if (stoi(give.substr(0, 2)) - stoi(birth.substr(0, 2)) < 0) {
                return 0;
            }
        }
    }
    return 1;
}

string Check_date(string birth_date) {
    string x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || (True_date(birth_date, x) == 0)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Дата выдачи паспорта не может отличатся от даты рождения менее чем на 14 лет! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

int HashFun(string key, int length) {
    int n = 0;
    for (int i = 0; i < key.size(); i++) {
        n += pow(int(key[i]), 2);
    }
    n %= length;
    return n;
}

string Generate_hash() {
    string k;
    for (int i = 0; i < 11; i++) {
        if (i == 4) {
            k += '-';
        }
        else {
            k += '0' + rand() % ('9' - '0');
        }
    }
    return k;
}

string Generate_tree() {
    string k;
    for (int i = 0; i < 3; i++) {
        k += 'A' + rand() % ('Z' - 'A');
    }
    k += '-';
    for (int i = 0; i < 3; i++) {
        k += '0' + rand() % ('9' - '0');
    }
    return k;
}

string Generate_list() {
    string k;
    for (int i = 0; i < 9; i++) {
        k += '0' + rand() % ('9' - '0');
    }
    return k;
}

void Normal_Show_hash(Passenger* head) {
    Passenger* p = head;
    while (p != NULL) {
        cout << p->passport << " ";
        p = p->next;
    }
}

void Normal_Show_tree(Flight* root, int n) {
    Flight* cur = root;
    if (cur != NULL) {
        Normal_Show_tree(cur->right, n + 1);
        for (int i = 1; i <= n; i++) {
            cout << "\t";
        }
        cout << cur->number << endl;
        Normal_Show_tree(cur->left, n + 1);
    }
}

int High(Flight* cur) {
    if (cur != NULL) {
        return cur->high;
    }
    return 0;
}

void NewHigh(Flight* cur) {
    int hl = High(cur->left);
    int hr = High(cur->right);
    if (hl > hr) {
        cur->high = hl + 1;
    }
    else {
        cur->high = hr + 1;
    }
}

Flight* TurnLeft(Flight* root) {
    Flight* cur = root;
    Flight* c = root->right;
    cur->right = c->left;
    c->left = cur;
    NewHigh(cur);
    NewHigh(c);
    return c;
}

Flight* TurnRight(Flight* root) {
    Flight* cur = root;
    Flight* c = root->left;
    cur->left = c->right;
    c->right = cur;
    NewHigh(cur);
    NewHigh(c);
    return c;
}

Flight* Balance(Flight* root) {
    Flight* cur = root;
    NewHigh(cur);
    if (High(cur->right) - High(cur->left) == 2) {
        if (High(cur->right->right) - High(cur->right->left) < 0) {
            cur->right = TurnRight(cur->right);
        }
        return TurnLeft(cur);
    }
    if (High(cur->right) - High(cur->left) == -2) {
        if (High(cur->left->right) - High(cur->left->left) > 0) {
            cur->left = TurnLeft(cur->left);
        }
        return TurnRight(cur);
    }
    return cur;
}

Flight* Min_tree(Flight* current) {
    Flight* cur = current;
    if (cur->left != NULL) {
        return Min_tree(cur->left);
    }
    return cur;
}

Flight* ReplaceMin_tree(Flight* current) {
    Flight* cur = current;
    if (cur->left == NULL)
        return cur->right;
    cur->left = ReplaceMin_tree(cur->left);
    return Balance(cur);
}

int Delete_tree_list(struct Flight* root, vector <string>& a) {
    Flight* cur = root;
    if (cur == NULL) {
        return 0;
    }
    a.push_back(cur->number);
    Delete_tree_list(cur->left, a);
    Delete_tree_list(cur->right, a);
}

vector <string> Search_tree_fio(Ticket* head, string number) {
    Ticket* cur = head;
    vector <string> str;
    if (head != NULL) {
        if (cur->number_flight != number) {
            cur = cur->next;
            while (cur->next != head && cur->next != NULL) {
                if (cur->next->number_flight != number) {
                    cur = cur->next;
                }
                else {
                    str.push_back(cur->passport);
                }
            }
        }
        else {
            str.push_back(cur->passport);
        }
    }
    return str;
}

void badSymbolList(string str, int size, int badSymbol[256]) {
    for (int i = 0; i < 256; i++) {
        badSymbol[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badSymbol[(int)str[i]] = i;
    }
}

bool JustSearch(string str, string piece) {
    int m = size(piece);
    int n = size(str);
    int badSymbol[256];
    bool f = 0;
    badSymbolList(piece, m, badSymbol);
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && piece[j] == str[s + j]) {
            j--;
        }
        if (j < 0) {
            f = 1;
            if (s + m < n) {
                s += m - badSymbol[str[s + m]];
            }
            else {
                s++;
            }
        }
        else {
            s += max(1, j - badSymbol[str[s + j]]);
        }
    }
    return f;
}

int Search_tree(Flight* root, string n, int count, Flight** str, int* f);

void Show_list(Ticket* head) {
    Ticket* p = head;
    if (p != NULL) {
        cout << p->number_ticket << " " << p->passport << " " << p->number_flight << endl;
        p = p->next;
        if (p != NULL) {
            while (p != head && p != NULL) {
                cout << p->number_ticket << " " << p->passport << " " << p->number_flight << endl;
                p = p->next;
            }
        }
    }
}

int Lengh_list(Ticket* head) {
    Ticket* p = head;
    int n = 1;
    p = p->next;
    if (p != NULL) {
        while (p != head) {
            n++;
            p = p->next;
        }
    }
    return n;
}

int Search_list(Ticket* head, string value) {
    Ticket* cur = head;
    if (head != NULL) {
        if (cur->number_ticket != value) {
            while (cur->next != head && cur->next != NULL) {
                if (cur->next->number_ticket == value) {
                    return 0;
                }
                cur = cur->next;
            }
        }
        else {
            return 0;
        }
    }
    return 1;
}

void Sort(string** mass, int left_cur, int right_cur) {
    string elem, first, second;
    int left = left_cur;
    int right = right_cur;
    elem = mass[left_cur][0];
    first = mass[left_cur][1];
    second = mass[left_cur][2];
    while (left_cur < right_cur) {
        while ((mass[right_cur][0] >= elem) && (left_cur < right_cur)) {
            right_cur--;
        }
        if (left_cur != right_cur) {
            mass[left_cur][0] = mass[right_cur][0];
            mass[left_cur][1] = mass[right_cur][1];
            mass[left_cur][2] = mass[right_cur][2];
            left_cur++;
        }
        while ((mass[left_cur][0] <= elem) && (left_cur < right_cur)) {
            left_cur++;
        }
        if (left_cur != right_cur) {
            mass[right_cur][0] = mass[left_cur][0];
            mass[right_cur][1] = mass[left_cur][1];
            mass[right_cur][2] = mass[left_cur][2];
            right_cur--;
        }
    }
    mass[left_cur][0] = elem;
    mass[left_cur][1] = first;
    mass[left_cur][2] = second;
    int place = left_cur;
    left_cur = left;
    right_cur = right;
    if (left_cur < place) {
        Sort(mass, left_cur, place - 1);
    }
    if (right_cur > place) {
        Sort(mass, place + 1, right_cur);
    }
}

void Sort_list(Ticket** head) {
    Ticket* cur = *head;
    int n = Lengh_list(cur);
    string** mass = new string * [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new string[3];
    }
    cur = *head;
    for (int i = 0; i < n; i++) {
        mass[i][0] = cur->number_ticket;
        mass[i][1] = cur->number_flight;
        mass[i][2] = cur->passport;
        cur = cur->next;
    }
    Sort(mass, 0, n - 1);
    cur = *head;
    for (int i = 0; i < n; i++) {
        cur->number_ticket = mass[i][0];
        cur->number_flight = mass[i][1];
        cur->passport = mass[i][2];
        cur = cur->next;
    }
    for (int i = 0; i < n; i++) {
        delete[]mass[i];
    }
    delete[] mass;
}

string Delete_list_hash(Ticket** head, string value) {
    Ticket* cur = *head;
    Ticket* p;
    string str = "";
    if (*head != NULL) {
        if (cur->passport != value) {
            while (cur->next != *head && cur->next != NULL) {
                if (cur->next->passport == value) {
                    str = cur->next->number_flight;
                    p = cur;
                    cur->next = cur->next->next;
                    cur->next->prew = p;
                }
                cur = cur->next;
            }
        }
        else {
            str = cur->number_flight;
            if (Lengh_list(*head) > 2) {
                cur = (*head)->prew;
                *head = (*head)->next;
                (*head)->prew = cur;
                cur->next = *head;
            }
            else if (Lengh_list(*head) == 2) {
                *head = (*head)->next;
                (*head)->prew = NULL;
                (*head)->next = NULL;
            }
            else {
                *head = NULL;
            }
        }
    }
    return str;
}

string Delete_list_tree(Ticket** head, string value) {
    Ticket* cur = *head;
    Ticket* p;
    string str = "";
    if (*head != NULL) {
        if (cur->number_flight != value) {
            while (cur->next != *head && cur->next != NULL) {
                if (cur->next->number_flight == value) {
                    p = cur;
                    cur->next = cur->next->next;
                    cur->next->prew = p;
                }
                cur = cur->next;
            }
        }
        else {
            str = cur->number_flight;
            if (Lengh_list(*head) > 2) {
                cur = (*head)->prew;
                *head = (*head)->next;
                (*head)->prew = cur;
                cur->next = *head;
            }
            else if (Lengh_list(*head) == 2) {
                *head = (*head)->next;
                (*head)->prew = NULL;
                (*head)->next = NULL;
            }
            else {
                *head = NULL;
            }
        }
    }
    return str;
}

void Add_hash(Passenger** head, string passport, string place, string date_give, string fio, string date_birth, int* f) {
    Passenger* cur = *head;
    Passenger* p = new Passenger;
    p->passport = passport;
    p->place = place;
    p->date_give = date_give;
    p->fio = fio;
    p->date_birth = date_birth;
    if (cur == NULL) {
        p->next = NULL;
        *head = p;
    }
    else if (cur->passport == passport) {
        *f = 0;
        cout << "Ошибка! Номер пасспорта должен быть уникален! Повторите ввод" << endl;
    }
    else {
        while (cur->next) {
            if (cur->passport == passport) {
                *f = 0;
                cout << "Ошибка! Все значения должны быть уникальны! Повторите ввод" << endl;
            }
            cur = cur->next;
        }
        cur->next = p;
        p->next = NULL;
    }
}

void Delete_hash(Passenger** head, string value) {
    Passenger* cur = *head;
    if (cur->passport == value) {
        *head = cur->next;
    }
    else {
        while ((cur->next->passport != value)) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
}

void Show_hash(Passenger* head) {
    Passenger* p = head;
    while (p != NULL) {
        cout << setiosflags(ios::left) << setw(13) << p->passport << setw(15) << p->place << setw(12) << p->date_give << setw(33) << p->fio << setw(12) << p->date_birth << endl;
        p = p->next;
    }
}

void Clear_hash(Passenger** head, Flight* root, Ticket** head_list) {
    Passenger* cur = NULL;
    Flight* pointer;
    string str;
    int f = 0;
    if (*head != NULL) {
        do {
            str = Delete_list_hash(head_list, (*head)->passport);
            if (str != "") {
                Search_tree(root, str, 0, &pointer, &f);
                pointer->sit_free += 1;
                f = 0;
            }
        } while (str != "");
        while ((*head)->next != NULL) {
            cur = *head;
            *head = (*head)->next;
            delete cur;
            do {
                str = Delete_list_hash(head_list, (*head)->passport);
                if (str != "") {
                    Search_tree(root, str, 0, &pointer, &f);
                    pointer->sit_free += 1;
                    f = 0;
                }
            } while (str != "");
        }
    }
    *head = NULL;
}

bool Search_hash_passport(Passenger* head, Passenger** pointer, string passport) {
    Passenger* cur = head;
    bool f = 0;
    while (cur != NULL) {
        if (cur->passport == passport) {
            *pointer = cur;
            f = 1;
        }
        cur = cur->next;
    }
    return f;
}

bool Search_hash_fio(Passenger* head, string fio) {
    Passenger* cur = head;
    bool f = 0;
    while (cur != NULL) {
        if (cur->fio == fio) {
            cout << setiosflags(ios::left) << setw(13) << cur->passport << setw(15) << cur->place << setw(12) << cur->date_give << setw(33) << cur->fio << setw(12) << cur->date_birth << endl;
            f = 1;
        }
        cur = cur->next;
    }
    return f;
}

Flight* Add_tree(Flight* root, string number, string name, string out, string in, string date, string time, int sit, int sit_free, int* f) {
    Flight* cur = root;
    if (cur == NULL) {
        Flight* p = new Flight;
        p->right = NULL;
        p->left = NULL;
        p->number = number;
        p->name = name;
        p->out = out;
        p->in = in;
        p->date = date;
        p->time = time;
        p->sit = sit;
        p->sit_free = sit_free;
        p->high = 1;
        return p;
    }
    if (cur->number == number) {
        *f = 0;
        cout << "Ошибка! Номер авиарейса должен быть уникален! Повторите ввод" << endl;
        return cur;
    }
    if (number > cur->number) {
        cur->left = Add_tree(cur->left, number, name, out, in, date, time, sit, sit_free, f);
    }
    else {
        cur->right = Add_tree(cur->right, number, name, out, in, date, time, sit, sit_free, f);
    }
    return Balance(cur);
}

Flight* Delete_tree(Flight* root, string n) {
    Flight* cur = root;
    if (cur == NULL) {
        return NULL;
    }
    if (n > cur->number) {
        cur->left = Delete_tree(cur->left, n);
    }
    else if (n < cur->number) {
        cur->right = Delete_tree(cur->right, n);
    }
    else {
        Flight* left = cur->left;
        Flight* right = cur->right;
        delete cur;
        if (right == NULL) {
            return left;
        }
        Flight* min = Min_tree(right);
        min->right = ReplaceMin_tree(right);
        min->left = left;
        return Balance(min);
    }
    return Balance(cur);
}

void Show_tree(Flight* root, int n) {
    Flight* p = root;
    if (p != NULL) {
        Show_tree(p->right, n + 1);
        cout << setiosflags(ios::left) << setw(9) << p->number << setw(19) << p->name << setw(13) << p->out << setw(13) << p->in << setw(13) << p->date << setw(7) << p->time << setw(3) << p->sit << setw(3) << p->sit_free << endl;
        Show_tree(p->left, n + 1);
    }
}

Flight* Clear_tree(Flight* root, Ticket** head_list) {
    vector <string> a;
    int f = 0;
    string str;
    Flight* pointer;
    Delete_tree_list(root, a);
    for (int i = 0; i < a.size(); i++) {
        do {
            str = Delete_list_tree(head_list, a[i]);
            if (str != "") {
                Search_tree(root, str, 0, &pointer, &f);
                pointer->sit_free += 1;
                f = 0;
            }
        } while (str != "");
        root = Delete_tree(root, a[i]);
    }
    return NULL;
}

int Search_tree(Flight* root, string n, int count, Flight** str, int* f) {
    Flight* cur = root;
    if (cur->number == n) {
        *str = cur;
        *f = 1;
        return 1;
    }
    if (pow(cur->high, 3) < count) {
        return 0;
    }
    if (n > cur->number) {
        Search_tree(cur->left, n, count + 1, str, f);
    }
    else {
        Search_tree(cur->right, n, count + 1, str, f);
    }
}

int Search_tree_pieces(struct Flight* root, string n, int* f) {
    Flight* cur = root;
    if (cur == NULL) {
        return 0;
    }
    Search_tree_pieces(cur->left, n, f);
    Search_tree_pieces(cur->right, n, f);
    if (JustSearch(cur->in, n)) {
        *f = 1;
        cout << setiosflags(ios::left) << setw(9) << cur->number << setw(19) << cur->name << setw(13) << cur->out << setw(13) << cur->in << setw(13) << cur->date << setw(7) << cur->time << setw(3) << cur->sit << setw(3) << cur->sit_free << endl;
    }
}

void Add_list(Ticket** head, string ticket, string pas, string fl) {
    Ticket* cur = *head;
    Ticket* cur2;
    Ticket* p = new Ticket;
    p->passport = pas;
    p->number_flight = fl;
    p->number_ticket = ticket;
    if (cur == NULL) {
        p->next = NULL;
        p->prew = NULL;
        *head = p;
    }
    else if (cur->next == NULL && cur->prew == NULL) {
        p->next = cur;
        p->prew = cur;
        cur->prew = p;
        cur->next = p;
    }
    else {
        cur2 = cur->prew;
        cur->prew = p;
        p->next = cur;
        p->prew = cur2;
        cur2->next = p;
    }
    Sort_list(head);
}

bool Delete_list(Ticket** head, string value) {
    Ticket* cur = *head;
    Ticket* p;
    bool f = 0;
    if (*head != NULL) {
        if (cur->number_ticket != value) {
            while (cur->next != *head && cur->next != NULL) {
                if (cur->next->number_ticket == value) {
                    p = cur;
                    cur->next = cur->next->next;
                    cur->next->prew = p;
                    f = 1;
                }
                cur = cur->next;
            }
        }
        else {
            if (Lengh_list(*head) > 2) {
                cur = (*head)->prew;
                *head = (*head)->next;
                (*head)->prew = cur;
                cur->next = *head;
            }
            else if (Lengh_list(*head) == 2) {
                *head = (*head)->next;
                (*head)->prew = NULL;
                (*head)->next = NULL;
            }
            else {
                *head = NULL;
            }
            f = 1;
        }
    }
    return f;
}

int Menu(int* first) {
    int second = 0;
    system("cls");
    cout << "Хотите зарегистрироваться в нашей системе или настроить свой аккаунт введите 1\nВы сотрудник авиакампании и хотите взаимодействовать с авиарейсами нажмите 2\nХотите получить доступ к кассам, нажмите 3\nХотите выйти нажмите 0" << endl;
    vector <int> a = { 0, 1, 2, 3 };
    *first = In_menu(a);
    a.clear();
    system("cls");
    switch (*first) {
    case 1:
        cout << "Хотите зарегистрировать новый аккаунт, нажмите 1\nХотите удалить свой аккаунт, нажмите 2\nХотите вывести все аккаунты нажмите 3\nХотите удалить данные о всех аккаунтах, нажмите 4\nХотите найти пассажира по паспорту, нажмите 5\nХотите найти пассажира по ФИО, нажмите 6\nХотите вернуться на предыдущую страницу, нажмите 0" << endl;
        a = { 0, 1, 2, 3, 4, 5, 6 };
        second = In_menu(a);
        a.clear();
        break;
    case 2:
        cout << "Хотите добавить новый авиарейс, нажмите 1\nХотите удалить авиарейс, нажмите 2\nХотите вывести данные о всех авиарейсах, нажмите 3\nХотите отчистить данные о всех авиарейсах, нажмите 4\nХотите найти авиарейс по номеру, нажмите 5\nХотите найти авиарейс по фрагменту названия аэропорта прибытия, нажмите 6\nХотите вернуться на предыдущую страницу, нажмите 0" << endl;
        a = { 0, 1, 2, 3, 4, 5, 6 };
        second = In_menu(a);
        a.clear();
        break;
    case 3:
        cout << "Хотите купить билет, нажмите 1\nХотите оформить возврат, нажмите 2\nХотите вернуться на предыдущую страницу, нажмите 0" << endl;
        a = { 0, 1, 2 };
        second = In_menu(a);
        a.clear();
        break;
    case 0:
        cout << "Спасибо за использование нашей системы";
        second = 0;
        break;
    }
    return second;
}

int main() {
    setlocale(0, "");
    //Инициализация:
    ifstream fr_hash, fr_tree;
    fr_hash.open("Test_hash.txt");
    fr_tree.open("Test_tree.txt");
    string passport, place, date_give, fio, date_birth, number, name, out, in, date, time, sit_str, sit_free_str, ticket, str;
    int n, sit, sit_free;
    int i = 5, j = 5, f = 0;
    string s = Check_date("12.10.2002");
    Flight* tree = NULL;
    Passenger** hash = new Passenger * [10] {};
    Ticket* list = NULL;
    Passenger* point = NULL;
    Flight* pointer = NULL;
    vector <string> passports;
    while (!fr_hash.eof()) {
        getline(fr_hash, passport, '/');
        getline(fr_hash, place, '/');
        getline(fr_hash, date_give, '/');
        getline(fr_hash, fio, '/');
        getline(fr_hash, date_birth, '\n');
        n = HashFun(passport, 10);
        Add_hash(&hash[n], passport, place, date_give, fio, date_birth, &f);
    } //Чтение Хеш-таблицы из файла
    while (!fr_tree.eof()) {
        getline(fr_tree, number, '/');
        getline(fr_tree, name, '/');
        getline(fr_tree, out, '/');
        getline(fr_tree, in, '/');
        getline(fr_tree, date, '/');
        getline(fr_tree, time, '/');
        getline(fr_tree, sit_str, '/');
        getline(fr_tree, sit_free_str, '\n');
        sit = stoi(sit_str);
        sit_free = stoi(sit_free_str);
        tree = Add_tree(tree, number, name, out, in, date, time, sit, sit_free, &f);
    } //Чтение дерева из файла
    while (i != 0) {
        j = Menu(&i);
        if (j != 0) {
            switch (i) {
            case(1):
                system("cls");
                switch (j) {
                case 1: //Добавление
                    cout << "Введите данные добавляемого пассажира:" << endl;
                    while (f != 1) {
                        cout << "Пасспорт: ";
                        passport = Mask_passport();
                        cout << "ФИО пассажира: ";
                        getline(cin, fio, '\n');
                        cout << "Дата рождения пассажира: ";
                        getline(cin, date_birth, '\n');
                        cout << "Место выдачи: ";
                        getline(cin, place, '\n');
                        cout << "Дата выдачи: ";
                        date_give = Check_date(date_birth);
                        n = HashFun(passport, 10);
                        f = 1;
                        Add_hash(&hash[n], passport, place, date_give, fio, date_birth, &f);
                    }
                    for (int i = 0; i < 10; i++) {
                        Show_hash(hash[i]);
                    }
                    f = 0;
                    break;
                case 2: //Удаление
                    cout << "Введите номер пасспорта удаляемого пассажира: ";
                    passport = Mask_passport();
                    n = HashFun(passport, 10);
                    Delete_hash(&hash[n], passport);
                    for (int i = 0; i < 10; i++) {
                        Show_hash(hash[i]);
                    }
                    do {
                        str = Delete_list_hash(&list, passport);
                        if (str != "") {
                            Search_tree(tree, str, 0, &pointer, &f);
                            pointer->sit_free += 1;
                            f = 0;
                        }
                    } while (str != "");
                    break;
                case 3: //Вывод
                    cout << "Вот данные всех пассажиров:" << endl;
                    for (int i = 0; i < 10; i++) {
                        Show_hash(hash[i]);
                    }
                    break;
                case 4: //Чистка
                    for (int i = 0; i < 10; i++) {
                        Clear_hash(&hash[i], tree, &list);
                    }
                    cout << "Все удалил" << endl;
                    break;
                case 5: //Поиск по паспорту
                    cout << "Введите номер пасспорта искомого пассажира: ";
                    passport = Mask_passport();
                    n = HashFun(passport, 10);
                    if (Search_hash_passport(hash[n], &point, passport)) {
                        cout << point->passport << " " << point->place << " " << point->date_give << " " << point->fio << " " << point->date_birth << endl;
                    }
                    else {
                        cout << "Не найдено такого пассажира" << endl;
                    }
                    break;
                case 6: //Поиск по ФИО
                    cout << "Введите ФИО искомого пассажира: ";
                    getline(cin, fio, '\n');
                    for (int i = 0; i < 10; i++) {
                        if (Search_hash_fio(hash[i], fio)) {
                            f = 1;
                        }
                    }
                    if (f == 0) {
                        cout << "Не найдено такого пассажира" << endl;
                    }
                    f = 0;
                    break;
                }
                system("pause");
                break;
            case(2):
                system("cls");
                switch (j) {
                case 1:
                    cout << "Введите данные добавляемого авиврейса" << endl;
                    while (f != 1) {
                        cout << "Введите номер авиарейса: ";
                        number = Mask_number_flight();
                        cout << "Введите название авиакомпании: ";
                        getline(cin, name, '\n');
                        cout << "Введите аэропорт отправления: ";
                        getline(cin, out, '\n');
                        cout << "Введите аэропорт прибытия: ";
                        getline(cin, in, '\n');
                        cout << "Введите дату отправления: ";
                        getline(cin, date, '\n');
                        cout << "Введите время отправления: ";
                        getline(cin, time, '\n');
                        cout << "Введите количество мест в самолете: ";
                        getline(cin, sit_str, '\n');
                        cout << "Введите количество свободных мест в самолете: ";
                        getline(cin, sit_free_str, '\n');
                        sit = stoi(sit_str);
                        sit_free = stoi(sit_free_str);
                        f = 1;
                        tree = Add_tree(tree, number, name, out, in, date, time, sit, sit_free, &f);
                    }
                    Show_tree(tree, 0);
                    f = 0;
                    break;
                case 2:
                    cout << "Введите номер удаляемого авиарейса: ";
                    number = Mask_number_flight();
                    tree = Delete_tree(tree, number);
                    Show_tree(tree, 0);
                    do {
                        str = Delete_list_tree(&list, number);
                        if (str != "") {
                            Search_tree(tree, str, 0, &pointer, &f);
                            f = 0;
                            pointer->sit_free += 1;
                        }
                    } while (str != "");
                    break;
                case 3:
                    cout << "Вот данные о всех авиарейсах:" << endl;
                    Show_tree(tree, 0);
                    break;
                case 4:
                    tree = Clear_tree(tree, &list);
                    cout << "Все удалил" << endl;
                    break;
                case 5:
                    cout << "Введите номер искомого авиарейса: ";
                    number = Mask_number_flight();
                    Search_tree(tree, number, 0, &pointer, &f);
                    if (f != 1) {
                        cout << "Не найдено такого авиарейса" << endl;
                    }
                    else {
                        cout << pointer->number << " " << pointer->name << " " << pointer->out << " " << pointer->in << " " << pointer->date << " " << pointer->time << " " << pointer->sit << " " << pointer->sit_free << endl;
                        passports = Search_tree_fio(list, number);
                        if (passports.size() != 0) {
                            cout << "Список пассажиров, зарегестрированных на рейс:" << endl;
                            for (int i = 0; i < passports.size(); i++) {
                                n = HashFun(passports[i], 11);
                                Search_hash_passport(hash[n], &point, passport);
                                cout << point->passport << " " << point->place << " " << point->date_give << " " << point->fio << " " << point->date_birth << endl;
                            }
                        }
                        else {
                            cout << "На этот рейс не зарегистрированно пасажиров" << endl;
                        }
                    }
                    f = 0;
                    break;
                case 6:
                    cout << "Введите фрагмент названия искомого аэропорта: ";
                    getline(cin, number, '\n');
                    Search_tree_pieces(tree, number, &f);
                    if (f != 1) {
                        cout << "Не найдено такого авиарейса" << endl;
                    }
                    f = 0;
                    break;
                }
                system("pause");
                break;
            case(3):
                system("cls");
                switch (j) {
                case 1:
                    cout << "Здравствуйте, заполните все необходимые данные для регистрации на рейс" << endl;
                    while (f != 1) {
                        cout << "Введите свой номер пасспорта: ";
                        passport = Mask_passport();
                        n = HashFun(passport, 10);
                        f = Search_hash_passport(hash[n], &point, passport);
                        if (f != 1) {
                            cout << "Не найдено такого пассажира. Повторите ввод!" << endl;
                        }
                    }
                    f = 0;
                    cout << "Введите номер авиарейса на который хотите зарегистрироваться: ";
                    while (f != 1) {
                        number = Mask_number_flight();
                        Search_tree(tree, number, 0, &pointer, &f);
                        if (f != 1) {
                            cout << "Не найдено такого авиарейса. Повторите ввод!" << endl;
                        }
                    }
                    f = 0;
                    if (pointer->sit_free > 0) {
                        while (f != 1) {
                            ticket = Generate_list();
                            f = Search_list(list, ticket);
                        }
                        f = 0;
                        cout << "Поздравляем вас с успешной регистрацией, номер вашего билета: " << ticket << endl;
                        pointer->sit_free -= 1;
                        Add_list(&list, ticket, passport, number);
                    }
                    else {
                        cout << "Извините, на этот рейс нет свободных мест" << endl;
                    }
                    break;
                case 2:
                    cout << "Здравствуйте, заполните все необходимые данные для возврата билета на рейс" << endl;
                    while (f != 1) {
                        cout << "Введите свой номер пасспорта: ";
                        passport = Mask_passport();
                        n = HashFun(passport, 10);
                        f = Search_hash_passport(hash[n], &point, passport);
                        if (f != 1) {
                            cout << "Не найдено такого пассажира. Повторите ввод!" << endl;
                        }
                    }
                    f = 0;
                    while (f != 1) {
                        cout << "Введите номер авиарейса на который вы хотите вернуть билет: ";
                        number = Mask_number_flight();
                        Search_tree(tree, number, 0, &pointer, &f);
                        if (f != 1) {
                            cout << "Не найдено такого авиарейса. Повторите ввод!" << endl;
                        }
                    }
                    f = 0;
                    cout << "Введите номер своего билета: ";
                    ticket = Mask_number_ticket();
                    if (Delete_list(&list, ticket)) {
                        cout << "Поздравляем, вы успешно вернули билет" << endl;
                        pointer->sit_free += 1;
                        Show_list(list);
                    }
                    else {
                        cout << "Извените, не найденно такого билета" << endl;
                    }
                }
                system("pause");
                break;
            }
        }
    }
    fr_hash.close();
    fr_tree.close();
    return 0;
}