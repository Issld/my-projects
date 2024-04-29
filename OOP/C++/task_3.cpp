#include <iostream>
#include <string>

using namespace std;

class KomplChis {
private:
    int r;
    int fi;
    string s;
public:
    KomplChis(int, int, string);
    ~KomplChis();
    friend void operator * (const KomplChis&, const KomplChis&);
    void operator / (const KomplChis &);
    void operator == (const KomplChis &);
    void operator ~ ();
    void operator ! ();
    void Show(int, int);
};

KomplChis::KomplChis(int r, int fi, string s = "") {
    if (r != 0 && fi != 0) {
        cout << "Аргументы комплексного числа: r = " << r << "; fi = " << fi << endl;
    }
    this->r = r;
    this->fi = fi;
    this->s = s;
}


KomplChis::~KomplChis() {
    cout << "Сработал деструктор" << endl;
}

void KomplChis::Show(int r, int fi) {
    cout << r << " * (cos(" << fi << "°) + i*(sin(" << fi << "°))" << endl;
}

void operator * (const KomplChis& ob1, const KomplChis& ob2) {
    cout << "Полученное произведение комплексных чисел имеет вид: ";
    cout << ob1.r * ob2.r << " * (cos(" << ob1.fi + ob2.fi << "°) + i*(sin(" << ob1.fi + ob2.fi << "°))" << endl;
}

void KomplChis::operator / (const KomplChis& ob) {
    cout << "Полученное частное комплексных чисел имеет вид: ";
    this->KomplChis::Show(r * ob.r, abs(fi - ob.fi));
}

void KomplChis::operator == (const KomplChis& ob) {
    if (r == ob.r) {
        if (abs(fi - ob.fi) % 180 == 0) {
            cout << "Комплексные числа равны" << endl;
        }
        else {
            cout << "Комплексные числа не равны" << endl;
        }
    }
    else {
        cout << "Комплексные числа не равны" << endl;
    }
}

void KomplChis::operator ~ () {
    if (s != "") {
        cout << "Получено комплексное число: " << s << endl;
    }
    int i = 0;
    string st = "";
    while (s[i] != '*') {
        st += s[i];
        i++;
    }
    r = stoi(st);
    while ((s[i - 1] != 's') || (s[i] != '(')) {
        i++;
    }
    i++;
    st = "";
    while (s[i] != ')') {
        st += s[i];
        i++;
    }
    fi = stoi(st);
    cout << "При извлечении получены аргументы комплексного числа: r = " << r << "; fi = " << fi << endl;
}

void KomplChis::operator ! () {
    s = to_string(r) + "*(cos(" + to_string(fi) + "°) + i*sin(" + to_string(fi) + "°))";
    cout << "Преобразование аргументов в полноценное комплексное число: " << s << endl;
}

int main(){
	setlocale(0, "");
    //system("color F0");
    cout << "Первый объект:" << endl;
    KomplChis a(5, 30);
    !a;
    cout << "\nВторой объект:" << endl;
    KomplChis b(0, 0, "5*(cos(50°) + i*sin(50°))");
    ~b;
    cout << endl;
    a * b;
    a / b;
    a == b;
    cout << "\nТретий объект:" << endl;
    KomplChis c(0, 0, "5*(cos(210°) + i*sin(210°))");
    ~c;
    cout << "\nЕго сравнение с первым элементом:" << endl;
    a == c;
    cout << endl;
}