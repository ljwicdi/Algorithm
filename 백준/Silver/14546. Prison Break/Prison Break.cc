
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int L, W, A, B, C, D;
        cin >> L >> W >> A >> B >> C >> D;
        vector<vector<char>> v(W, vector<char>(L, '+'));
        vector<vector<bool>> visited(W, vector<bool>(L, false));
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v[0].size(); k++) {
                cin >> v[j][k];
            }
        }
        
        
        int startRow = W - B;
        int startCol = A - 1;
        int departureRow = W - D;
        int departureCol = C - 1;
        char ableRoute = v[startRow][startCol];
        queue<pair<int, int>> q;
        q.push(make_pair(startRow, startCol));
        visited[startRow][startCol] = true;
        
        string result = "NO";
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto s = q.front();
            if (s.first == departureRow && s.second == departureCol) {
                result = "YES";
                break;
            }
            q.pop();
            
            for (int j = 0; j < 4; j++) {
                int nx = s.first + dx[j];
                int ny = s.second + dy[j];
                
                if (nx < 0 || nx == W || ny < 0 || ny == L || v[nx][ny] != ableRoute) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        cout << result << "\n";
    }

    return 0;
}
