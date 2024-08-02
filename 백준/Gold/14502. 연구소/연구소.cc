#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int result = -1;

void calSafeZone(vector<vector<int>> & map) {
    
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                cnt++;
            }
        }
    }
    
    if (result < cnt) {
        result = cnt;
    }
}

void bfs(vector<vector<int>> & map) {
    
    vector<vector<int>> copyMap(N, vector<int>(M, 0));
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copyMap[i][j] = map[i][j];
        }
    }
    
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 바이러스
            if (copyMap[i][j] == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
           
            int nx = s.first + dx[i];
            int ny = s.second + dy[i];
                
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
                
            if (!visited[nx][ny] && map[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                copyMap[nx][ny] = 2;
            }
        }
        
    }
    
    calSafeZone(copyMap);
    
}

void solve(int depth, vector<vector<int>> & map, int currentI, int currentJ) {
    
    // 벽 3개 설치 완료
    if (depth == 3) {
        bfs(map);
        return;
    }

    if (currentJ == M - 1) {
        currentI++;
        currentJ = 0;
        if (currentI == N) {
            return;
        }
    }
    
    for (int i = currentI; i < N; i++) {
        for (int j = currentJ; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                solve(depth + 1, map, i, j);
                map[i][j] = 0;
            }
            
            if (j == M - 1) {
                currentJ = 0;
            }
        }
    }

}

int main() {
    
    cin >> N >> M;
    
    vector<vector<int>> map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                solve(1, map, i, j);
                map[i][j] = 0;
            }
        }
    }
    
    cout << result;
    
    return 0;
}