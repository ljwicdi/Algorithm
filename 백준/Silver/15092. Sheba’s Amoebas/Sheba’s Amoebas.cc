
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int m, n;
    cin >> m >> n;
    
    vector<int> v[m];
    vector<bool> visited[m];
    char data;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data;
            if (data == '#') {
                v[i].push_back(1);
            } else {
                v[i].push_back(0);
            }
            visited[i].push_back(false);
        }
    }
    
    int i = 0, j = 0;
    int result = 0;
    int nx, ny;
    while (1) {
        while (1) {
            if (v[i][j] == 1 && visited[i][j] == false) {
                break;
            }
            j++;
            if (j == n) {
                j = 0;
                i++;
            }
            if (i == m) {
                break;
            }
        }
        if (i == m) {
            break;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        result++;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (int k = 0; k < 8; k++) {
                nx = s.first + dx[k];
                ny = s.second + dy[k];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[nx][ny] == 0) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
