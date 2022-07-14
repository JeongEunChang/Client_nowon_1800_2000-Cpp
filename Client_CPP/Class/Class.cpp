#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
#include "Warrior.h"
#include "Debuffer.h"
using namespace std;

// 접근 제한자
// public : 외부에서 접근 가능한 키워드
// private : 외부에서 접근 불가능한 키워드
// protected : 자식 개체만 접근 가능한 키워드

class Coord {

private :
    int _x, _y;

public :
    // 객체지향 컨셉에서는
    // 되도록 객체가 다른 객체의 멤버변수를 직접 접근해서 수정하지 않도록 지향함
    // 보통 접근할 수 있는 함수를 제공하도록 함
    void SetCoord(int x, int y) {
        _x = x;
        _y = y;
    }
    
    int GetCoord_X() {
        return _x;
    }

    int GetCoord_Y() {
        return _y;
    }

    // 생성자 (얘는 함수)
    // 객체 생성 시 (메모리 공간 확보 시) 자동으로 호출
    Coord() { SetCoord(0, 0); };

    // 생성자 오버로딩
    Coord(int x, int y) {
        SetCoord(x, y);
    }
    // 소멸자 (얘도 함수)
    // 객체 해제 시 (메모리 공간 확보 해제 시) 자동으로 호출
    ~Coord() {};

    //연산자 오버로딩
    /*const Coord& operator = (const Coord& _other) {
        this->_x = _other._x;
        this->_y = _other._y;
        return this;*/
    //this 포인터
    //현재 객체 자기 자신을 가리키는 포인터
    //클래스 안에서 멤버에 접근할 때는 this 포인터가 생략되어있다
   // }

    //void Swap(const Coord& _other) {
    //    int tmpX = this->_x; // this 가 생략되어 있음
    //    int tmpY = _y;
    //    _x = _other._x;
    //    _y = _other._y;
    //}


    //// 연산자 정의
    //const Coord& operator + (const Coord& _other) {
    //    Coord tmpCoord;
    //    tmpCoord.SetCoord(_x + _other._x,
    //                      _y + _other._y);
    //    return tmpCoord;
    //}

};
   

int main()
{
   // Coord coord1;
   // cout << "(" << coord1.GetCoord_X() << "," << coord1.GetCoord_Y() << ")" << endl;
   // coord1.SetCoord(1, 2);
   // cout << "(" << coord1.GetCoord_X() << "," << coord1.GetCoord_Y() << ")" << endl;

    // 객체를 힙 영역에 동적할당 할 시
    // new 생성자
    // 형태로 할당함
   // Coord* coord2ptr = new Coord(5, 2);
   // cout << "(" << coord2ptr->GetCoord_X() << "," << coord2ptr->GetCoord_Y() << ")" << endl;
    
    
    // 클래스 간의 대입 연산 가능
    //cout << "(" << coord1.GetCoord_X() << "," << coord1.GetCoord_Y() << ")" << endl;
    //cout << "(" << coord2ptr->GetCoord_X() << "," << coord2ptr->GetCoord_Y() << ")" << endl;
    //coord1 = *coord2ptr;
   // (coord1 + *coord2ptr).;
    //cout << "(" << coord1.GetCoord_X() << "," << coord1.GetCoord_Y() << ")" << endl;
    
    
   // delete coord2ptr;

    //Warrior* warrior = new Warrior();              // 객체를 포인터로 선언하면 더 좋은가요? 또는 객체를 그냥 선언하는 게 아니라 동적할당으로 하면 더 좋은가요?@@@@@@@@@@@@@@@@
    Debuffer* debuffer = new Debuffer();  // 괄호 붙이는 이유가 무엇인가요? *$!@#$!@$!@$!@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    //debuffer->DecreaseHP(*warrior);
    debuffer->DecreaseHP();

  //컨트롤 알알 누르면  한꺼번에 수정 가능

    //delete warrior;
    delete debuffer;
    Debuffer debuffer1;
    debuffer1._damage = 10;
    strcpy(debuffer1._name, "하급디버퍼");

    Debuffer debuffer2 = debuffer1;
    cout << debuffer2._damage << ", " << debuffer2._name << endl;

    strcpy(debuffer2._name, "상급디버퍼");
    debuffer2._damage = 30;
    cout << "1번 디버퍼" << debuffer1._damage << ", " << debuffer1._name << endl;
    cout << "2번 디버퍼" << debuffer2._damage << ", " << debuffer2._name << endl;

    return 0;
}
