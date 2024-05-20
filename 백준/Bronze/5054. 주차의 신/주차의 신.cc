
#include <iostream>

using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int N, mi = 100, ma = -1, pos;
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> pos;
            if (pos < mi) {
                mi = pos;
            }
            
            if (ma < pos) {
                ma = pos;
            }
        }
        
        cout << (ma - mi) * 2 << "\n";
    }
    return 0;
}
