#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    
    // 28, 29, 30, 31
    int afterTwoWeeksDay = m + 14;
    if (n >= 8) {
        cout << n - 7;
    } else {
        if (afterTwoWeeksDay >= 28) {
            if (afterTwoWeeksDay - 31 == n) {
                cout << 31 - (7 - n);
            } else if (afterTwoWeeksDay - 30 == n) {
                cout << 30 - (7 - n);
            } else if (afterTwoWeeksDay - 29 == n) {
                cout << 29 - (7 - n);
            } else if (afterTwoWeeksDay - 28 == n) {
                cout << 28 - (7 - n);
            }
        } else {
            cout << m + 7;
        }
    }
    
    return 0;
}