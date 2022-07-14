#pragma once
#include "base.h"
class derived :
    public base
{
public:
        derived(){}
        //void f() { std::cout << "derived::f()" << std::endl; }
        //void g() { std::cout << "derived::g()" << std::endl; }
        // 
        virtual void g() { std::cout << "derived::g()" << std::endl; }
        //virtual void g(int a) { std::cout << "derived::g()" << a << std::endl; }
        int i = 2;
};

