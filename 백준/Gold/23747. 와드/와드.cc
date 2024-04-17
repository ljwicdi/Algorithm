#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    
    int row, col;
    cin >> row >> col;
    vector<vector<char>> map(row, vector<char>(col, '-'));
    vector<vector<char>> result(row, vector<char>(col, '#'));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
        }
    }
    
    int currentX, currentY;
    cin >> currentX >> currentY;
    currentX -= 1, currentY -= 1;
    
    string route;
    cin >> route;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for (int i = 0; i < route.length(); i++) {
        if (route[i] == 'U') {
            currentX = currentX - 1;
            continue;
        } else if (route[i] == 'R') {
            currentY = currentY + 1;
            continue;
        } else if (route[i] == 'D') {
            currentX = currentX + 1;
            continue;
        } else if (route[i] == 'L') {
            currentY = currentY - 1;
            continue;
        } else if (route[i] == 'W') {
            visited[currentX][currentY] = true;
            result[currentX][currentY] = '.';
            queue<pair<int, int>> q;
            q.push({currentX, currentY});
            
            while (!q.empty()) {
                auto s = q.front();
                q.pop();
                
                for (int j = 0; j < 4; j++) {
                    int nx = s.first + dx[j];
                    int ny = s.second + dy[j];
                    
                    if (nx < 0 || ny < 0 || nx >= row || ny >= col) {
                        continue;
                    }
                    
                    if (map[nx][ny] != map[s.first][s.second]) {
                        continue;
                    }
                    
                    if (visited[nx][ny] == false) {
                        visited[nx][ny] = true;
                        result[nx][ny] = '.';
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
    result[currentX][currentY] = '.';
    
    for (int i = 0; i < 4; i++) {
        int nx = currentX + dx[i];
        int ny = currentY + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= row || ny >= col) {
            continue;
        }
        
        result[nx][ny] = '.';
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}
