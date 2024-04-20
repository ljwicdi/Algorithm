
#include <iostream>
#include <vector>

using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    // 1, 1, 1, 2, 2, 3, 4, 5, 7, 9
    vector<long long> dp(101, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;
    
    for (int i = 11; i < 101; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
    
    int N;
    for (int i = 0; i < testCase; i++) {
        cin >> N;
        cout << dp[N] << "\n";
    }
    
    
    return 0;
}
