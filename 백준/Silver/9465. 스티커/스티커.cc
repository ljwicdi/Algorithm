#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int n;
        
        cin >> n;
        vector<int> score[2];
        
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                int data;
                cin >> data;
                score[j].push_back(data);
            }
        }
    
        if (n == 1) {
            cout << max(score[0][0], score[1][0]) << "\n";
            continue;
        }
        
        vector<vector<int>> dp(2, vector<int>(n, 0));
    
        dp[0][0] = score[0][0];
        dp[1][0] = score[1][0];
        dp[0][1] = score[1][0] + score[0][1];
        dp[1][1] = score[0][0] + score[1][1];
    
        for (int j = 2; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                if (k == 0) {
                    dp[k][j] = max(max(dp[0][j - 2], dp[1][j - 2]), dp[1][j - 1]) + score[k][j];
                   
                } else if (k == 1) {
                    dp[k][j] = max(max(dp[1][j - 2], dp[0][j - 2]), dp[0][j - 1]) + score[k][j];
                  
                }
            }
        }
        
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    
    return 0;
}