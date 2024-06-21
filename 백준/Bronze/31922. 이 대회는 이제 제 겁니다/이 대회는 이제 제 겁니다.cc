
#include <iostream>
using namespace std;
int main() {
    
    int A, P, C;
    cin >> A >> P >> C;
    
    if (A + C > P) {
        cout << A + C;
    } else {
        cout << P;
    }

    return 0;
}