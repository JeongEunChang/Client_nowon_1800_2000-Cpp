#include <iostream>
#include "derived.h"
#include "base.h"
using namespace std;

//class base
//{
//public:
//    base() :i(1) {}
//    void f() { std::cout << "base::f()" << std::endl; }
//    virtual void g() { std::cout << "base::g()" << std::endl; }
//    int i;
//};
//
//class derived : public base
//{
//public:
//    derived() : i(2) {}
//    void f() { std::cout << "derived::f()" << std::endl; }
//    virtual void g() { std::cout << "derived::g()" << std::endl; }
//    int i;
//};

void sum()
{
    cout << "12" << endl;
}

int main()
{
    base* abc = new base();
    derived* zxc = new derived();
    zxc = abc;
    base b;
    derived d;
    b = d;
    base& rbb = b;
    base& rbd = d;

    //rbb.f(); // base::f() 호출
    //rbb.g(); // base::g() 호출
    //rbd.f(); // derived에서 오버라이딩 되어 있 지만 가상함수가 아니므로 rbd의 타입에 따라 base::f() 호출
    //rbd.g(); // derived에서 오버라이딩 되어 있고 base에서 g가 가상함수이므로 실제 객체 d의 타입에 따라 derived::g() 호출
    //b.f();   // derived에서 오버라이딩 되어 있는 derived::f() 호출
    //b.g();   // derived에서 오버라이딩 되어 있는 derived::g() 호출 
    //std::cout << sum() << std::endl; // base에 선언된 i인 1 출력
    //std::cout << d.g() << std::endl; // derived에서 i를 오버라이딩 하였으므로 2 출력'

    zxc->f();
}

