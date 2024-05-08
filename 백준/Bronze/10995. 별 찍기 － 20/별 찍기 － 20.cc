
#include <iostream>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    string str1 = "";
    string str2 = "";
    
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i % 2 == 0) {
            str1 += "*";
        } else {
            str1 += " ";
        }
    }
    
    for (int i = 0; i < 2 * n; i++) {
        if (i % 2 == 0) {
            str2 += " ";
        } else {
            str2 += "*";
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << str1;
        } else {
            cout << str2;
        }
        cout << "\n";
    }

    return 0;
}
