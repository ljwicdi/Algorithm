
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int main()
{
    int R, C;
    cin >> R >> C;
    vector<int> v[R];
    vector<bool> visited[R];
    string str;
    int startX, startY, departureX, departureY;
    for (int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < C; j++) {
         
            if (str[j] == '*') {
                v[i].push_back(1);
            } else {
                v[i].push_back(0);
            }
            
            if (str[j] == 'C') {
                startX = i;
                startY = j;
            }
            if (str[j] == 'B') {
                departureX = i;
                departureY = j;
            }

            visited[i].push_back(false);
        }
    }
    
    queue<node> q;
    node nd;
    nd.x = startX;
    nd.y = startY;
    nd.distance = 0;
    q.push(nd);
    visited[startX][startY] = true;
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        if (s.x == departureX && s.y == departureY) {
            result = s.distance;
            break;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
        
        
            if (nx < 0 || nx == R || ny < 0 || ny == C || v[nx][ny] == 1) {
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
    
    cout << result;
    return 0;
}
