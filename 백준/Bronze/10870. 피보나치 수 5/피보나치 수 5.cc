
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    
    vector<long long> dp;
    dp.push_back(0);
    dp.push_back(1);
    
    if (n <= 1) {
        cout << dp[n];
    } else {
        for (int i = 2; i <= n; i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        cout << dp[n];
    }

    return 0;
}
