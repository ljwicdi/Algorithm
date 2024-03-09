
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int N;
        int cnt = 0;
        cin >> N;
        vector<vector<char>> v(N, vector<char>(N, '-'));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int, int>> q;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> v[j][k];
                if (v[j][k] == 'w') {
                    q.push(make_pair(j, k));
                    visited[j][k] = true;
                }
            }
        }
        
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (int j = 0; j < 8; j++) {
                int nx = s.first + dx[j];
                int ny = s.second + dy[j];
                
                if (nx < 0 || nx == N || ny < 0 || ny == N || v[nx][ny] == 'b') {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    

    return 0;
}
