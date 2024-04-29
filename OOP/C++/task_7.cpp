#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class STL {
private:
    vector <int> a;
    int m1 = 0;
    int m2 = 100;
public:
    STL(int n) {
        int x;
        for (int i = 0; i < n; i++) {
            a.push_back(m1 + rand() % m2);
        }
        cout << "Вектор имеет вид:" << endl;
        Show(a);
    }
    ~STL() {
        cout << "Вызван деструктор" << endl;
    }
    void Task_1() {
        vector <int> rez;
        copy_if(a.begin(), a.end(), back_inserter(rez), [](int x) {return x > 10; });
        cout << "\nЗначения больше 10:" << endl;
        Show(rez);
        cout << "Их колличество: " << rez.size() << endl;
        cout << endl;
    }
    void Task_2() {
        cout << "Корни из всех элементов:" << endl;
        for (vector <int>::iterator i = a.begin(); i != a.end(); i++) {
            cout << pow(*i, 0.5) << " ";
        }
        cout << endl;
    }
    void Task_3() {
        cout << "\nСумма всех элементов вектора: " << accumulate(a.begin(), a.end(), 0) << endl;
        cout << endl;
    }
    void Show(vector <int> x) {      
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    setlocale(0, "");
    //system("color F0");
    STL a(10);
    a.Task_1();
    a.Task_2();
    a.Task_3();
    return 0;
}