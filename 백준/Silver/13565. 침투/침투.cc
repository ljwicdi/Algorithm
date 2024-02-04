#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    
    int M, N;
    cin >> M >> N;

    string str;
    vector<int> v[M];
    queue<pair<int, int>> q;
    vector<vector<bool>> visited (M, vector<bool> (N, false));
    for (int i = 0; i < M; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (i == 0) {
                if (str[j] == '0') {
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
            if (str[j] == '1') {
                v[i].push_back(1);
            } else {
                v[i].push_back(0);
            }
        }
    }
    
    
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    string result = "NO";
    
    while (!q.empty()) {
        auto s = q.front();
        if (s.first == M - 1) {
            result = "YES";
            break;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            nx = s.first + dx[i];
            ny = s.second + dy[i];
            
            // 공간에서 벗어남
            if (nx >= M || nx < 0 || ny >= N || ny < 0) {
                continue;
            }
            
            if (visited[nx][ny] == false && v[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    cout << result;
    return 0;
}
