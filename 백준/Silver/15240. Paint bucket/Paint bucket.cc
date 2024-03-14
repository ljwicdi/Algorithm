
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> v(R, vector<int>(C, 0));
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    string str;
    for (int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            v[i][j] = str[j] - '0';
        }
    }
    
    int Y, X, K;
    cin >> Y >> X >> K;
    
    queue<pair<int, int>> q;
    q.push(make_pair(Y, X));
    visited[Y][X] = true;
    char ableRoute = v[Y][X];
    v[Y][X] = K;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.first + dx[i];
            int ny = s.second + dy[i];
            
            if (nx < 0 || nx == R || ny < 0 || ny == C || v[nx][ny] != ableRoute) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
                v[nx][ny] = K;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    return 0;
}
