#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*vector<int> tmpVec;

    tmpVec.push_back(10);
    vector<int>:: iterator iter = tmpVec.begin();
    int tmpValue = *iter;*/

    vector<int>::iterator iter;
    vector<int>::iterator* ptriter;
    iter = iter++;
    ++iter;


    return 0;
}