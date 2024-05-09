
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> A(10), B(10);
    for (int i = 0; i < 10; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> B[i];
    }
    
    int aCnt = 0, bCnt = 0;
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) {
            aCnt++;
        } else if (A[i] < B[i]) {
            bCnt++;
        }
    }
    
    if (aCnt > bCnt) {
        cout << "A";
    } else if (aCnt < bCnt) {
        cout << "B";
    } else {
        cout << "D";
    }
    return 0;
}
