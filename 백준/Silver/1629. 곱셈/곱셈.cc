#include <iostream>
using namespace std;

long long a, b, c;

long long solve(long long a, long long b) {
    if (b == 1) {
        return a % c;
    }
    
    long long k = solve(a, b / 2);
    k = (k * k) % c;
    if (b % 2 == 1) {
        k = (k * a) % c;
    }
    
    return k;
}

int main() {

    cin >> a >> b >> c;
    
    cout << solve(a, b);

    return 0;
}