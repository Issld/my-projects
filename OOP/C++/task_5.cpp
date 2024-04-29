#include <iostream>

using namespace std;

class B {
protected:
    int b;
public:
    B() {
        b = 0;
        cout << "Вызван конструктор по умолчанию класса B" << endl;
    };
    ~B();
    B(int);
    void Show();
};

class D1 : virtual public B {
private:
    int d1;
public:
    D1(int);
    ~D1();
    void Show();
};

class D2 : virtual protected B {
private:
    int d2;
public:
    D2(int);
    ~D2();
    void Show();
};

class D3 : public D2 {
private:
    int d3;
public:
    D3(int, int);
    ~D3();
    void Show();
};

class D4 : virtual protected D1, virtual private D3 {
private:
    int d4;
public:
    D4(int, int, int, int, int);
    ~D4();
    void Show();
};

B::B(int a) {
    cout << "Вызван конструктор класса B" << endl;
    b = a;
}

D1::D1(int a) : B() {
    cout << "Вызван конструктор класса D1" << endl;
    d1 = a;
}

D2::D2(int a) : B() {
    cout << "Вызван конструктор класса D2" << endl;
    d2 = a;
}

D3::D3(int a, int c) : D2(c) {
    cout << "Вызван конструктор класса D3" << endl;
    d3 = a;
}

D4::D4(int a, int c, int e, int f, int h) : D3(e, f), D1(c) {
    cout << "Вызван конструктор класса D4" << endl;
    d4 = a;
    b = h;
}

B::~B() {
    cout << "Сработал деструктор класса B" << endl;
}

D1::~D1() {
    cout << "Сработал деструктор класса D1" << endl;
}

D2::~D2() {
    cout << "Сработал деструктор класса D2" << endl;
}

D3::~D3() {
    cout << "Сработал деструктор класса D3" << endl;
}

D4::~D4() {
    cout << "Сработал деструктор класса D4" << endl;
}

void B::Show() {
    cout << "Значение переменной в классе B: " << b << endl;
}

void D1::Show() {
    cout << "Значение переменной в классе D1: " << d1 << endl;
    this->B::Show();
}

void D2::Show() {
    cout << "Значение переменной в классе D2: " << d2 << endl;
    this->B::Show();
}

void D3::Show() {
    cout << "Значение переменной в классе D3: " << d3 << endl;
    this->D2::Show();
}

void D4::Show() {
    cout << "Значение переменной в классе D4: " << d4 << endl;
    this->D1::Show();
    this->D3::Show();
}

int main() {
    setlocale(0, "");
    system("color F0");
    D4 a(1, 2, 3, 4, 5);
    a.Show();
    return 0;
}