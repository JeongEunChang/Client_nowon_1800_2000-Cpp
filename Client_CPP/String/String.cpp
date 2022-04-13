#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main()
{
    const int DEFAULT_SIZE = 10;
    // 기존 C 문자열

    // 영어 문자형은 1byte 이지만, 한글 같은 글자는 2byte
    /*char firstName[DEFAULT_SIZE];
    char lastName[DEFAULT_SIZE];*/

    cout << "성을 입력하세요";

    // C++ 문자열
    string firstName, lastName;
    
    // cin.get(first,DEFAULT_SIZE).get();
    // cin.get(first,DEFAULT_SIZE).ignore(DEFAULT_SIZE, '\n');
    getline(cin, firstName);

    cout << "이름을 입력하세요";

    getline(cin, lastName);

    //cin >> firstName;
    //cin >> lastName;

    cout << "성은 " << firstName << "이요, 이름은 " << lastName << "이다" << endl;



    // 문자열 클래스의 활용

    // 기존 C 문자열처럼 인덱스 접근이 가능하다
    cout << firstName[0] << endl;

    // 인덱스 접근을 활용한 for문도 가능하다
    for (int i = 0; i < firstName.length(); i++)
    { 
        cout << firstName[i];
    }
    cout << endl;

    cout << firstName.length() << endl;
    cout << firstName.size() << endl;



    // append
    // 문자열을 추가하는 메소드
    string str1, str2, str3;
    str1.append("Hello World!");
    str2.append("Hello World!", 6, 5);
    str3.append(4,'!');
    
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;


    // find()
    // 문자열을 찾는 메소드
    // 문자열을 찾는데 실패하면 string::npos; -> unsigned 형의 멕시멈 값
    
    if (str1.find("Hello", 0) != string::npos)
        cout << "Hello 찾는데 성공" << endl;
    else
        cout << "Hello 찾는데 실패" << endl;



    // compare()
    // 두 문자열을 비교하는 메소드
    // 같을 경우 0 , 인자보다 사전 순으로 앞에 있을 경우 음수, 뒤에 있을 경우 양수
    cout << (str1.compare(str2) == 0) << endl;
    cout << (str1.compare(str2) < 0) << endl;
    cout << (str1.compare(str2) > 0) << endl;



    // replace()
    // 인자로 넣어준 문자열로 대체하는 메소드
    // 문자열.replace(대체 문자열 시작 위치, 대체 문자열 길이, 새로운 문자열);
    str1.replace(0, str2.length(), str3);
    cout << str1 << endl;

    string str = "12312312312312312312";
    cout << str.capacity() << endl;
    cout << str.max_size() << endl;
}



// 메소드랑 함수 차이 2222@@@@@@@@@@@@@@@@@@@@@@@@@@@
