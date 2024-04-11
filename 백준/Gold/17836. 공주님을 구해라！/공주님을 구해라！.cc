#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
    bool weapon;
};
int main()
{
    int row, col, limit;
    cin >> row >> col >> limit;
    vector<vector<int>> map(row, vector<int>(col, 0));
    vector<vector<vector<bool>>> visited(row, vector<vector<bool>>(col, vector<bool>(2, false)));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> map[i][j];
        }
    }
    
    queue<node> q;
    if (map[0][0] != 2) {
        q.push({0, 0, 0, false});
        visited[0][0][0] = true;
    }
    else {
        q.push({0, 0, 0, true});
        visited[0][0][1] = true;
    }
        
    bool isTrue = false;
    int result = 0;
    
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.distance > limit) {
            q.pop();
            continue;
        }
        if (s.x == row - 1 && s.y == col - 1 && s.distance <= limit) {
            result = s.distance;
            isTrue = true;
            break;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            // 무기를 가지고 있는 경우
            if (s.weapon == true) {
                if (nx < 0 || ny < 0 || nx >= row || ny >= col) {
                    continue;
                }
                
                if (visited[nx][ny][1] == false) {
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, s.distance + 1, true});
                }
            } else {
                
                if (nx < 0 || ny < 0 || nx >= row || ny >= col || map[nx][ny] == 1) {
                    continue;
                }
                
                if (visited[nx][ny][0] == false) {
                    visited[nx][ny][0] = true;
                    
                    if (map[nx][ny] == 2) 
                        q.push({nx, ny, s.distance + 1, true});
                    else if (map[nx][ny] == 0)
                        q.push({nx, ny, s.distance + 1, false});
                }
            }
        }
        q.pop();
        
        
    }
    
    if (!isTrue) {
        cout << "Fail";
    } else {
        cout << result;
    }
    
    return 0;
}
