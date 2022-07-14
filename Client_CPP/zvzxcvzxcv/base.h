#pragma once
#include <iostream>

class base
{
	public:
	    base(){}
	    void f() { std::cout << "base::f()" << std::endl; }
	    virtual void g() { std::cout << "base::g()" << std::endl; }
		void g(int a) { std::cout << "base::g()" << a << std::endl; }
	    int i = 1;

};

