
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
    int startX, startY;
    cin >> startY >> startX;
    vector<vector<int>> v(8, vector<int>(8, 0));
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    visited[8 - startX][startY - 1] = true;
    
    int departureX, departureY;
    cin >> departureY >> departureX;

    queue<node> q;
    node nd;
    nd.x = 8 - startX;
    nd.y = startY - 1;
    nd.distance = 0;
    q.push(nd);
    
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int nx, ny;
    int result = 0;
    while(!q.empty()) {
        auto s = q.front();
       
        if (s.x == 8 - departureX && s.y == departureY - 1) {
            result = s.distance;
            break;
        }
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
            
            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
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
