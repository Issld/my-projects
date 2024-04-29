#include <iostream>

using namespace std;

class A

{
public:    void f() { cout << 1; }
};

class B : public A

{
public:    void f() { cout << 2; }
};
int main()

{
    B b;         A& a = b;        a.f();
    return 0;

}