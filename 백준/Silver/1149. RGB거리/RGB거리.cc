
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> cost(N, vector<int>(3, 0));
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    
    for (int i = 1; i < N; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    } 
    
    cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
    
    return 0;
}