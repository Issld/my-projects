#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

#include <iostream>

using namespace std;

int In() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.rdbuf()->in_avail() > 1)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введены некорректные данные! \nПовторите ввод: ";
        cin >> x;
    }
    return x;
}

int In_size() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.rdbuf()->in_avail() > 1) || x <= 0) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введены некорректные данные! \nПовторите ввод: ";
        cin >> x;
    }
    return x;
}

struct Struct {
    int a;
    Struct* prew;
    Struct* next;
};

int Check(Struct* head, int n) {
    Struct* cur = head;
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (cur->a != 0) {
            f = 1;
        }
        cur = cur->next;
    }
    return f;
}

void Add(Struct** head, int a) {
    Struct* cur = *head;
    Struct* cur2;
    Struct* p = new Struct;
    p->a = a;
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
}

void Show(Struct* head) {
    Struct* p = head;
    cout << p->a << " ";
    p = p->next;
    if (p != NULL) {
        while (p != head) {
            cout << p->a << " ";
            p = p->next;
        }
    }
}

int Lengh(Struct* head) {
    Struct* p = head;
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

void DeleteAll(Struct** head) {
    Struct* cur = *head;
    Struct* cur2;
    int n = Lengh(*head);
    for (int i = 0; i < n; i++) {
        cur2 = cur;
        cur = cur->next;
        delete cur2;
    }
}

void Task(Struct** head, Struct** headNew, int k, int n) {
    Struct* cur = *head;
    Struct* curNew = *head;
    bool f = 0;
    int count = 0;
    if (n != 1) {
        while (cur->a + count < k) {
            count += cur->a;
            Add(headNew, cur->a);
            cur = cur->next;
        }
        Add(headNew, cur->a);
    }
    else {
        while (cur->a + count < k) {
            count += cur->a;
            Add(headNew, cur->a);
        }
        Add(headNew, cur->a);
    }
}

void Delete(Struct** head, int value) {
    Struct* cur = *head;
    Struct* k;
    Struct* p;
    if (cur->a != value) { 
        cur = cur->next;
        while (cur->next != *head) {
            if (cur->next->a != value) {
                cur = cur->next;
            }
            else {
                p = cur->next;
                cur->next = cur->next->next;
                cur = cur->next;
                delete p;
            }
        }
    }
    else {
        cur = *head;
        *head = (*head)->next;
        delete cur;
    }
}

int main() {
    setlocale(0, "");
    Struct* list = NULL;
    Struct* listNew = NULL;
    int k, n, a;
    bool f = 0;
    cout << "Введите число K: ";
    k = In();
    cout << "Введите число элементов структуры: ";
    n = In_size();
    while (f != 1) {
        for (int i = 0; i < n; i++) {
            cout << "Введите элемент структуры: ";
            a = In();
            Add(&list, a);
        }
        f = Check(list, n);
        if (f == 0) {
            DeleteAll(&list);
            list = NULL;
            cout << "Для этой задачи неприемлем массив состоящий только из 0! Повторите ввод:" << endl;
        }
    }
    cout << "Исходная последовательность:\t";
    Show(list);
    Task(&list, &listNew, k, n);
    cout << "\nИскомая подпоследовательность:\t";
    Show(listNew);
    DeleteAll(&list);
    DeleteAll(&listNew);
    /*Show(list);
    Delete(&list, 3);
    Show(list);*/
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();
    return 0;
}