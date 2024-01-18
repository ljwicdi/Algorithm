
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; 
    // a : 몬스터의 방어율 수치
    // b : 유저의 방무;

    double minus = b / 100.0;
    double result = (double) a - a * minus;
    
    if (result >= 100) {
        cout << "0";
    } else {
        cout << "1";
    }
    return 0;
}
