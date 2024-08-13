#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> myMap;
const long long MOD = 1000000007;

long long solve(long long n) {
    
    if (myMap.find(n) != myMap.end()) {
        return myMap[n];
    }
     
    if (n % 2 == 0) {
        long long half1 = solve(n + 1) % MOD;
        long long half2 = solve(n - 1) % MOD;
        myMap[n] = (half1 - half2 + MOD) % MOD;  // 음수 처리
    } else {
        long long half3 = solve(n / 2) % MOD;
        long long half4 = solve(n / 2 + 1) % MOD;
        myMap[n] = (half3 * half3 % MOD + half4 * half4 % MOD) % MOD;
    }
    
    return myMap[n];
}

int main() {
    
    long long n;
    cin >> n;
    
    myMap[0] = 0;
    myMap[1] = 1;
    myMap[2] = 1;
    myMap[3] = 2;
    myMap[4] = 3;
    
    cout << solve(n) << endl;
    
    return 0;
}