#include <iostream>
#include "MyTemplate.h"
using namespace std;

// 포인터를 쓰는 경우 vs 참조자를 쓰는 경우
// 포인터 : 직접 해당 변수의 주소값이 필요한 경우
// 참조자 : 해당 변수의 값만 필요한 경우


template <typename T>
void Swap(T& a, T& b);


int main()
{
    int a = 3;
    int b = 5;
    double c = 2.0;

    MyTemplate<int, double> mytemplate;
    mytemplate.ForceSum(a, c);

    Swap<int>(a, b); // Swap<int>(a, b); 가 생략되어 있음


    return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
