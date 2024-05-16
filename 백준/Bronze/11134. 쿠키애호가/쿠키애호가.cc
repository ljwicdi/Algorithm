
#include <iostream>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int N, C;
        cin >> N >> C;
        
        if (N % C == 0) {
            cout << N / C << "\n";
        } else {
            cout << N / C + 1 << "\n";
        }
    }

    return 0;
}
