
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int row, col;
struct node {
    int x;
    int y;
    int distance;
    // 메모리를 많이 씀 
    // vector<vector<bool>> visited(row, vector<bool>(col, false));
};

int main() {
    // 아.. 불이 하나만 있는게 아니네 ..
    // 먼저 불이 번지는 시간대를 기록해보자 ..
    // 불정보를 기록하면 되지않을까 min() .
    
    // visited를 각각 해줘야하는데. . 이것을 한번에 처리할 수 없을까? 
    cin >> row >> col;
    vector<vector<char>> map(row, vector<char>(col, '-'));
    vector<vector<int>> fire(row, vector<int>(col, 100000000));
    vector<vector<bool>> fireVisited(row, vector<bool>(col, false));
    char data;
 
    int jihoonStartX, jihoonStartY;
    queue<node> q;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> data;
            map[i][j] = data;
            if (data == 'F') {
                node nd;
                nd.x = i;
                nd.y = j;
                nd.distance = 0;
                fireVisited[i][j] = true;
                fire[i][j] = 0;
                q.push(nd);
            }
            if (data == 'J') {
                jihoonStartX = i;
                jihoonStartY = j;
            }
        }
    }
    

    // 일단 먼저 불을 번져보자 (불이 번진 시간을 기록)
    
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto s = q.front();
        fire[s.x][s.y] = s.distance;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= row || ny >= col || map[nx][ny] == '#') {
                continue;
            }
            
            
            if (fireVisited[nx][ny] == false) {
                fireVisited[nx][ny] = true;
                node nd;
                nd.x = nx;
                nd.y = ny;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
            
            
        }
    }
    
   
    // 이제 지훈이가 탈출하게 해야함 
    node nd;
    nd.x = jihoonStartX;
    nd.y = jihoonStartY;
    nd.distance = 0;
    q.push(nd);
    vector<vector<bool>>jihoonVisited(row, vector<bool>(col, false));
    jihoonVisited[jihoonStartX][jihoonStartY] = true;
    
    
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.x == 0 || s.x == row - 1 || s.y == 0 || s.y == col - 1) {
            if (s.distance < fire[s.x][s.y] || fire[s.x][s.y] == 100000000) {
                result = s.distance + 1;
                cout << result;
                return 0;
            } else {
                q.pop();
                continue;
            }
        }
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = s.x + dx[k];
            int ny = s.y + dy[k];
            
            
            if (map[nx][ny] == '#' || fire[nx][ny] <= s.distance + 1) {
                continue;
            }
            
            if (jihoonVisited[nx][ny] == false) {
                    jihoonVisited[nx][ny] = true;
                    node nd;
                    nd.x = nx;
                    nd.y = ny;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                }
            
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}
