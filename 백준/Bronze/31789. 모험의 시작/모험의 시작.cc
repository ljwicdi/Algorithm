#include <iostream>
using namespace std;
int main() {
    int N, X, S;
    cin >> N;
    cin >> X >> S;
    
    bool posi = false;
    for (int i = 0; i < N; i++) {
        int c, p;
        cin >> c >> p;
        if (c <= X && p > S) {
            posi = true;
        }
    }
    
    if (posi) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}