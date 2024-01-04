
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // S -> T 
    // 1. 문자열 뒤에 A를 추가한다.
    // 2. 문자열을 뒤집고 뒤에 B를 추가한다.
    // 가능 : 1, 불가능 : 0
    // 거꾸로 역으로 추적 
    string S, T;
    cin >> S;
    cin >> T;
    
    for (int i = T.length() - 1; i >= 0; i--) {
        
        if (S == T) {
            cout << "1";
            return 0;
        }
        
        if (T[i] == 'A') {
            string temp;
            for (int j = 0; j < i; j++) {
                temp = temp + T[j];
            }
            T = temp;
            continue;
        }
        
        string temp;
        for (int j = i - 1; j >= 0; j--) {
            temp = temp + T[j];
        }
        
        T = temp;
    }
    
    cout << "0";
    return 0;
}
