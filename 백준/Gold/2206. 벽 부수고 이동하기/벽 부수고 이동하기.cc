#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x, y, distance;
    bool cracked;
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            v[i][j] = str[j] - '0';
        }
    }
    
    queue<node> q;
    q.push({0, 0, 1, false});
    
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    visited[0][0][0] = true;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        node s = q.front();
        q.pop();
        
        if (s.x == N - 1 && s.y == M - 1) {
            cout << s.distance << endl;
            return 0;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            
            if (v[nx][ny] == 1 && !s.cracked && !visited[nx][ny][1]) {
                visited[nx][ny][1] = true;
                q.push({nx, ny, s.distance + 1, true});
            } else if (v[nx][ny] == 0 && !visited[nx][ny][s.cracked]) {
                visited[nx][ny][s.cracked] = true;
                q.push({nx, ny, s.distance + 1, s.cracked});
            }
        }
    }
    
    cout << -1 << endl;
    return 0;
}
