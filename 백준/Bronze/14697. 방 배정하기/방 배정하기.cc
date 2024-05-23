
#include <iostream>
using namespace std;
int main() {
    
    int A, B, C, N;
    cin >> A >> B >> C >> N;
    
    bool isPos = false;
    
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            for (int k = 0; k <= 1000; k++) {
                if (A * i + B * j + C * k == N) {
                    isPos = true;
                }
            }
        }
    }
    
    if (isPos) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}
