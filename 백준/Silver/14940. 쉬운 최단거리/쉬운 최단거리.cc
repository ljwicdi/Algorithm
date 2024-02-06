
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
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    vector<int> result[n];
    vector<bool> visited[n];
    vector<bool> comp[n];
    int data;
    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> data;
            v[i].push_back(data);
            visited[i].push_back(false);
            result[i].push_back(0);
            if (data == 0) {
                comp[i].push_back(false);
            } else {
                comp[i].push_back(true);
            }
            if (data == 2) {
                startX = i;
                startY = j;
            }
        }
    }
    
    queue<node> q;
    node nd;
    nd.x = startX; nd.y = startY; nd.distance = 0;
    q.push(nd);
    visited[startX][startY] = true;
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    while (!q.empty()) {
        auto s = q.front();
        result[s.x][s.y] = s.distance;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
            
            if (nx >= n || nx < 0 || ny >= m || ny < 0 || v[nx][ny] == 0) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
                node nd;
                nd.x = nx; nd.y = ny; nd.distance = s.distance + 1;
                q.push(nd);
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (comp[i][j] == true && result[i][j] == 0 && v[i][j] != 2) {
                cout << "-1 ";
            } else {
                if (j == m - 1)
                    cout << result[i][j];
                else 
                    cout << result[i][j] << " ";
            }
            
        }
        cout << "\n";
    }
    return 0;
}
