
#include <iostream>
using namespace std;
int main() {
    int N, P;
    cin >> N;
    cin >> P;
    
    int result;
    if (N >= 20) {
        result = P - 2000 < P - P * 0.25 ? P - 2000 : P - P * 0.25;
    } else if (N >= 15) {
        result = P - 2000 < P - P * 0.10 ? P - 2000 : P - P * 0.10;
    } else if (N >= 10) {
        result = P - 500 < P - P * 0.10 ? P - 500 : P - P * 0.10;
    } else if (N >= 5) {
        result = P - 500;
    } else {
        result = P;
    }
    
    if (result < 0) {
        result = 0;
    }
    
    cout << result;
    return 0;
}