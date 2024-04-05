
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
    int k;
};

int main()
{
    int K;
    cin >> K;
    int row, col;
    cin >> col >> row;
    vector<vector<int>> v(row, vector<int>(col, 1));
    vector<vector<vector<bool>>> visited(row, vector<vector<bool>>(col, vector<bool>(31, false)));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }
    
    if (col == 1 && row == 1) {
        if (v[0][0] == 1) return -1;
    }
    
    if (v[row - 1][col - 1] == 1) {
        return -1;
    }
    
    queue<node> q;
    q.push({0, 0, 0, K});
    visited[0][0][K] = true;
    int result = -1;
    int dxNormal[4] = {-1, 0, 1, 0};
    int dyNormal[4] = {0, 1, 0, -1};
    int dxHorse[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dyHorse[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    // 원숭이 점프로 갈 수 없는 곳을 말 점프로 갈 수도 있다.
    // 방문처리 세심히
    // k값 때문에 처리할 수 있는데 방문처리 때문에 못할 수도 있다
    while (!q.empty()) {
        auto s = q.front();
        if (s.x == row - 1 && s.y == col - 1) {
            result = s.distance;
            break;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dxNormal[i];
            int ny = s.y + dyNormal[i];
            
            if (nx < 0 || ny < 0 || nx >= row || ny >= col || v[nx][ny] == 1) {
                continue;
            }
            
            if (visited[nx][ny][s.k] == false) {
                visited[nx][ny][s.k] = true;
                q.push({nx, ny, s.distance + 1, s.k});
            }
        }
        
        if (s.k > 0) {
            for (int i = 0; i < 8; i++) {
                int nx = s.x + dxHorse[i];
                int ny = s.y + dyHorse[i];
                
                if (nx < 0 || ny < 0 || nx >= row || ny >= col || v[nx][ny] == 1) {
                    continue;
                }
                
                if (visited[nx][ny][s.k - 1] == false) {
                    visited[nx][ny][s.k - 1] = true;
                    q.push({nx, ny, s.distance + 1, s.k - 1});
                }
            }
        }
        
        
    }
    cout << result;
    return 0;
}
