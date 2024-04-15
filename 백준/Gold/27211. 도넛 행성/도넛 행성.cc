#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int row, col;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }
    
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] == true || v[i][j] == 1) continue;
            // 구역의 수 
            result++;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            
            while (!q.empty()) {
                auto s = q.front();
                
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int nx = s.first + dx[k];
                    int ny = s.second + dy[k];
                    
                    if (nx == -1) {
                        nx = row - 1;
                    } else if (nx == row) {
                        nx = 0;
                    } else if (ny == -1) {
                        ny = col - 1;
                    } else if (ny == col) {
                        ny = 0;
                    }
                    
                    if (v[nx][ny] == 1) continue;
                    
                    if (visited[nx][ny] == false) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
