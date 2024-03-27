
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};
int main()
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<node> q;
    int total = M * N;
    int currentMature = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            if (v[i][j] == -1) {
                total--;
            }
            if (v[i][j] == 1) {
                currentMature++;
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }
    
    
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = -1;
    
    if (total == currentMature) {
        result = 0;
    }
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || v[nx][ny] != 0) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
                q.push({nx, ny, s.distance + 1});
                currentMature++;
                if (currentMature == total) {
                    result = s.distance + 1;
                    cout << result;
                    exit(0);
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
