
#include <iostream>
#include <string>
using namespace std;

string sol(long long N) {
    string result = "";
    
    while (N != 0) {
        result = to_string(N % 2) + result;
        N = N / 2;
    }
    
    return result;
}

int main() {
    
    long long N;
    cin >> N;
    
    cout << sol(N);
    return 0;
}
