#include <iostream>
#include <stdlib.h>

struct Mystruct
{
    int a;
};

int main()
{
    // c 에서 동적할당
    struct Mystruct* a = (Mystruct*)malloc(sizeof(Mystruct));
    free(a); // 함수 형태

    // c++ 에서 동적할당
    // new 키워드를 사용
    // 타입* 포인터 이름 = new 타입;
    Mystruct* mystruct = new Mystruct;
    delete mystruct;

    
    int* pi = new int;
    *pi = 100;
    std::cout << *pi << std::endl;
    delete pi; // 키워드 형태

    
    return 0;
}