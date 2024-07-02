#include <iostream>
using namespace std;
int main() {
    string str;
    cin >> str;
    
    int yCnt = 0, vowelCnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowelCnt++;
        }
        
        if (str[i] == 'y') {
            yCnt++;
        }
    }
    
    cout << vowelCnt << " " << vowelCnt + yCnt;

    return 0;
}