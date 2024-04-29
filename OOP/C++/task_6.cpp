#include <iostream>
#include <vector>

using namespace std;

class Errors {
public:
    void Error_2() {
        cout << "Ошибка! Не выполнить задание\nВ массиве нет нулевых элементов" << endl;
    }
    void Error_3() {
        cout << "Ошибка! Не выполнить задание\nВ массиве только один нулевой элемент" << endl;
    }
};

class Massive : public Errors {
private:
    int a[16];
    int index = 0;
public:
    Massive(int n) {
        try {
            if (n != 16) {
                throw(16);
            }
        }
        catch (int ex) {
            cout << "Ошибка! Введенный размер не соответствует шифру\nРазмер принудительно изменен и равен " << ex << endl;
        }
        for (int i = 1; i < 17; i++) {
            a[index] = i;
            index++;
            cout << "В массив а добавлен элемент: " << i << endl;
        }
        cout << "Значения элемента с номером 5 изменено на 0" << endl;
        a[4] = 0;
        //a[9] = 0;*/
        cout << endl;
    }
    ~Massive() {
        cout << "Вызван деструктор" << endl;
    }
    void Task_1() {
        int ind = 0, max = 0;
        for (int i = 0; i < index; i++) {
            if (a[i] > max) {
                max = a[i];
                ind = i;
            }
        }
        cout << "Индекс максимального элемента: " << ind << endl;
        cout << endl;
    }
    void Task_2() {
        vector <int> b;
        int f = 0;
        for (int i = 0; i < index; i++) {
            if (f == 1) {
                b.push_back(a[i]);
            }
            if (a[i] == 0) {
                if (f == 0) {
                    f = 1;
                }
                else if (f == 1) {
                    f = 2;
                    break;
                }
            }
        }
        if (f == 0) {
            Error_2();
        }
        else if (f == 1) {
            Error_3();
        }
        else {
            int pr = 1;
            cout << "Значения между двумя нулевыми элементами: ";
            for (int i = 0; i < b.size() - 1; i++) {
                cout << b[i] << " ";
                pr *= b[i];
            }
            cout << "\nИх произведение равно: " << pr << endl;
        }
        cout << endl;
    }
    void Task_3() {
        vector <int> x;
        for (int i = 1; i < index; i += 2) {
            x.push_back(a[i]);
        }
        for (int i = 0; i < index; i += 2) {
            x.push_back(a[i]);
        }
        for (int i = 0; i < index; i++) {
            a[i] = x[i];
        }
        cout << "Произошло преобразование! ";
        Show();
    }
    void Show() {
        cout << "Массив имеет вид: ";
        for (int i = 0; i < index; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(0, "");
    system("color F0");
    Massive a(16);
    a.Show();
    a.Task_1();
    a.Task_2();
    a.Task_3();
    return 0;
}