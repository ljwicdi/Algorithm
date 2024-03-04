
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    char data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> data;
            if (data == '*') {
                v[i][j] = 1;
            }
        }
    }
    
    
    
    int i = 0, j = 0;
    int result = 0;
    while (1) {
        while(1) {
            if (v[i][j] == 1 && visited[i][j] == false) {
                break;
            }
            j++;
            
            if (j == M) {
                i++;
                j = 0;
            }
            
            if (i == N) {
                break;
            }
        }
        
        if (i == N) {
            break;
        }
        
        result++;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int nx, ny;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                nx = s.first + dx[i];
                ny = s.second + dy[i];
                
                if (nx < 0 || nx == N || ny < 0 || ny == M || v[nx][ny] == 0) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    cout << result;
    

    return 0;
}
