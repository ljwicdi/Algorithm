
#include <iostream>
using namespace std;
int main() {
    
    int A, B, K, X;
    cin >> A >> B;
    cin >> K >> X;
    
    int cnt = 0;
    for (int i = A; i <= B; i++) {
        if (i >= K - X && i <= K + X) {
            cnt++;
        }
    }
    
    if (cnt == 0) {
        cout << "IMPOSSIBLE";
    } else {
        cout << cnt;
    }

    return 0;
}