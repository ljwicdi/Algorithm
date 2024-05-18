#include <iostream>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    int result;
    if (N == 1) {
        result = 1;
    } else if (N >= 2 && N < 4) {
        result = 2;
    } else if (N >= 4 && N < 8) {
        result = 4;
    } else if (N >= 8 && N < 16) {
        result = 8;
    } else if (N >= 16 && N < 32) {
        result = 16;
    } else if (N >= 32 && N < 64) {
        result = 32;
    } else {
        result = 64;
    }
    
    cout << result;
    
   
    return 0;
}
