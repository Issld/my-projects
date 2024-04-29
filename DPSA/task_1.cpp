#include <iostream>

using namespace std;

void In(int* a, int n){
    //cout << (n / 2) << " " << (-((n / 2) - 1)) << endl;
    for (int i = 0; i < n; i++) {
        a[i] = (-((n / 2) - 1)) + rand() % (n / 2);
    }
}

int InSize() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.rdbuf()->in_avail() > 1) || (x <= 1)) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введены некорректные данные! \nПовторите ввод: ";
        cin >> x;
    }
    return x;
}

void Task(int* a, int n, int* count) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            a[i] = abs(a[i]);
        }
        if (a[i] % 2 == 0) {
            *count += 1;
        }
    }
}

void Out(int count) {
    cout << "\nЧетных элементов: " << count << endl;
}

int main() {
    setlocale(0, "");
    int n, x;
    int count = 0;
    cout << "Введите количество элементов массива: ";
    n = InSize();
    int* a = new int[n];
    In(a, n);
    cout << "Исходный массив:\t";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nВыберете задачу, 1 для изменения массива, 2 для подсчета чётных элементов: ";
    cin >> x;
    Task(a, n, &count);
    switch (x) {
    case(1):
        cout << "\nИзмененный массив:\t";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        break;
    case(2):
        Out(count);
        break;
    }    
}