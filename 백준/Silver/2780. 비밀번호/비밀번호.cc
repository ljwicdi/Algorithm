
#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;
int main() {
    
    int testCase, N;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> N;
        long long dp[N + 1][10] = {0, }; 
        
        for (int j = 0; j < 10; j++) {
            dp[1][j] = 1;
        }
        
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < 10; k++) {
                switch (k) {
                    case 0:
                        dp[j][k] = dp[j][k] + dp[j - 1][7] % 1234567;
                        break;
                    case 1:
                        dp[j][k] = dp[j][k] + dp[j - 1][2] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][4] % 1234567;
                        break;
                    case 2:
                        dp[j][k] = dp[j][k] + dp[j - 1][1] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][3] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][5] % 1234567;
                        break;
                    case 3:
                        dp[j][k] = dp[j][k] + dp[j - 1][2] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][6] % 1234567;
                        break;
                    case 4:
                        dp[j][k] = dp[j][k] + dp[j - 1][1] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][5] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][7] % 1234567;
                        break;
                    case 5:
                        dp[j][k] = dp[j][k] + dp[j - 1][2] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][4] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][6] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][8] % 1234567;
                        break;
                    case 6:
                        dp[j][k] = dp[j][k] + dp[j - 1][3] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][5] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][9] % 1234567;
                        break;
                    case 7:
                        dp[j][k] = dp[j][k] + dp[j - 1][4] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][8] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][0] % 1234567;
                        break;
                    case 8:
                        dp[j][k] = dp[j][k] + dp[j - 1][5] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][7] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][9] % 1234567;
                        break;
                    case 9:
                        dp[j][k] = dp[j][k] + dp[j - 1][6] % 1234567;
                        dp[j][k] = dp[j][k] + dp[j - 1][8] % 1234567;
                        break;
                }
            }
        }
        
        long long result = 0;
        
        for (int j = 0; j < 10; j++) {
            result = result + dp[N][j];
        }
        
        cout << result % 1234567 << "\n";
        
    }
    return 0;
}
