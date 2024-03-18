
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int main() {
    int row, col;
    cin >> row >> col;
    
    vector<vector<char>> map(row, vector<char>(col, '-'));
    
    // 맵 정보 담음 
    string str;
    for (int i = 0; i < row; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            map[i][j] = str[j];
        }
    }
    
    // 모든 육지를 시작으로 max 거리를 계산
    // 음 .. 왜 무한루프 ?  -> 큐 삽입을 안했음 ㅋㅋ
    // for -> row, fol -> col로 하면 됐었다..
    
    int max = -1;
    vector<vector<bool>> startVisited(row, vector<bool>(col, false));
    int i = 0, j = 0;
    while (1) {
        while (1) {
            if (map[i][j] == 'L' && startVisited[i][j] == false) {
                startVisited[i][j] = true;
               
                break;
            }
            
            j++;
            if (j == col) {
                j = 0;
                i++;
            }
            if (i == row) {
                break;
            }
        }
        if (i == row) {
            break;
        }
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<node> q;
        node nd;
        nd.x = i;
        nd.y = j;
        nd.distance = 0; 
        visited[i][j] = true;
        q.push(nd);
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            
            auto s = q.front();
            if (max < s.distance) {
                max = s.distance;
            }
            q.pop();
            
            
            for (int k = 0; k < 4; k++) {
                int nx = s.x + dx[k];
                int ny = s.y + dy[k];
                
                if (nx < 0 || ny < 0 || nx >= row || ny >= col || map[nx][ny] == 'W') {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    node nd;
                    nd.x = nx;
                    nd.y = ny;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    
                }
            }
        }
    }
    
    cout << max;
    
    return 0;
}
