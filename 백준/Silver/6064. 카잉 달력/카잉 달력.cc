#include <iostream>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        
        // <x, y>는 몇 번째 해일까 ?
        bool posible = false;
        for (int i = 0; i < 2 * N; i++) {
            if ((x + i * M) % N == y || ((x + i * M) % N == 0 && N == y)) {
                posible = true;
                break;
            }
        }
        
        if (!posible) {
            cout << "-1\n";
            continue;
        }
        
        // 해가 존재하는 경우
        int result = x;
        while (1) {
            if (result % N != 0)  {
                if (result % N == y) {
                    break;
                }
            } else {
                if (N == y) {
                    break;
                }
            }
        
            result += M;
        }
        
        cout << result << "\n";
    }
    return 0;
}