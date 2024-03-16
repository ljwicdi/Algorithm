
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> v(m, vector<char>(n, '.'));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    string str;
    for (int i = 0; i < m; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            v[i][j] = str[j];
        }
    }
    
    int i = 0, j = 0;
    int result = 0;
    while (1) {
        while (1) {
            if (visited[i][j] == false && v[i][j] == '#') {
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
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (int k = 0; k < 8; k++) {
                int nx = s.first + dx[k];
                int ny = s.second + dy[k];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[nx][ny] == '.') {
                    continue;
                }
                
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << result;
    return 0;
}
