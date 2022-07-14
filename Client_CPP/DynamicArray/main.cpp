#include <iostream>
#include "DynamicArray.h"
using namespace std;

// 동적 할당으로 객체 선언하면 생성자 호출 안 함?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int main()
{
    DynamicArray da;
    da.Add(1);

    cout << "1을 찾을 수 있나여? " << da.IsExist(1) << endl;

    da.Remove(1);

    //da.Delete();
}
