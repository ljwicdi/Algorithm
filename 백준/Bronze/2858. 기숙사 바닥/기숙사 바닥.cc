
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int R, B;
    cin >> R >> B;
    
    // 약수
    pair<int, int> result;
    for (int i = 1; i <= B; i++) {
        if (B % i == 0) {
            if ((B / i) * 2 + (i + 2) * 2 == R) {
                if (i > B / i) {
                    result = make_pair(i + 2, B / i + 2);
                } else {
                    result = make_pair(B / i + 2, i + 2);
                }
            }
        }
    }
    
    cout << result.first << " " << result.second;

    return 0;
}
