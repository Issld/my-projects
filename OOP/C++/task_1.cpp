#include <iostream>
#include <cmath>

using namespace std;

class Mass {
private:
    int m[5];
    int nom = 0;
    int count = 5;
public:
    void Input();
    void Print();
    void Task();
};

void Mass::Input() {
    int x;
    for (int i = 0; i < count; i++) {
        cout << "Введите элемент массива: ";
        cin >> x;
        m[i] = x;
    }
    for (int i = 0; i < count; i++) {
        if (m[i] < 0) {
            nom = m[i];
            break;
        }
    }
};

void Mass::Print() {
    cout << "Массив имеет вид: ";
    for (int i = 0; i < count; i++) {
        cout << m[i] << " ";
    }
    cout << endl;
    if (nom == 0) {
        cout << "Нет отрицательных элментов" << endl;
    }
    else {
        cout << "Значение максимального отрицательного элемента: " << nom << endl;
    }
    cout << endl;
};

void Mass::Task() {
    for (int i = 0; i < count; i++) {
        if (m[i] < 0) {
            if (m[i] > nom) {
                nom = m[i];
            }
        }
    }
}

int main() {
    setlocale(0, "");
    Mass a;
    cout << "Объект A" << endl;
    a.Input();
    a.Print();
    a.Task();
    Mass b;
    cout << "Объект B" << endl;
    b.Input();
    b.Print();
    b.Task();
}