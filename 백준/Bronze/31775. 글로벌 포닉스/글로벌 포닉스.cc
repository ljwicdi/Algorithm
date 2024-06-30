
#include <iostream>
#include <vector>
using namespace std;
int main() {
    string str;
    bool check[3] = {false, };
    for (int i = 0; i < 3; i++) {
        cin >> str;
        if (str[0] == 'l') {
            check[0] = true;
        } else if (str[0] == 'k') {
            check[1] = true;
        } else if (str[0] == 'p') {
            check[2] = true;
        }
    }
    
    if (check[0] && check[1] && check[2]) {
        cout << "GLOBAL";
    } else {
        cout << "PONIX";
    }
    
    return 0;
}