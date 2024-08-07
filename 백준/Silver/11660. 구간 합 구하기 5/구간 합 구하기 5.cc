#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N, M;
    cin >> N >> M;
    
    int map[N + 1][N + 1], dp[N + 1][N + 1];
    
    for (int i = 0; i <= N; i++) {
        map[0][i] = 0;
        map[i][0] = 0;
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    
    dp[1][1] = map[1][1];
    for (int i = 2; i <= N; i++) {
        dp[1][i] = dp[1][i - 1] + map[1][i];
        dp[i][1] = dp[i - 1][1] + map[i][1];
    }
    
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= N; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}