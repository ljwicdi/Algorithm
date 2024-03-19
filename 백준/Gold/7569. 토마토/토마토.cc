
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int z;
    int distance;
};

int main() {
    // 토마토가 전부 다 익는 시간 
    int row, col, height;
    cin >> col >> row >> height;
    vector<vector<vector<int>>> box(row, vector<vector<int>> (col, vector<int>(height, -1)));
    vector<vector<vector<bool>>> visited(row, vector<vector<bool>> (col, vector<bool>(height, false)));
    queue<node> q;
    int ableTotal = col * row * height;
    int currentMature = 0;
    for (int h = 0; h < height; h++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> box[i][j][h];
                if (box[i][j][h] == -1) {
                    ableTotal--;
                }
                if (box[i][j][h] == 1) {
                    q.push({i, j, h, 0});
                    currentMature++;
                    visited[i][j][h] = true;
                }
            }
        }
    }
    
    if (currentMature == ableTotal) {
        cout << "0";
        return 0;
    }
    // ableTotal => 가능한 익은 토마토 수 
    
    int dx[6] = {-1, 0, 1, 0, 0, 0};
    int dy[6] = {0, 1, 0, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        q.pop();
        
        
        for (int i = 0; i < 6; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            int nz = s.z + dz[i];
            
            if (nx < 0 || ny < 0 || nz < 0 || nx == row || ny == col || nz == height || box[nx][ny][nz] == -1) {
                continue;
            }
            
            if (!visited[nx][ny][nz]) {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, s.distance + 1});
                if (box[nx][ny][nz] == 0) {
                    box[nx][ny][nz] = 1;
                    currentMature++;
                    if (currentMature == ableTotal) {
                        result = s.distance + 1;
                        cout << result;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
