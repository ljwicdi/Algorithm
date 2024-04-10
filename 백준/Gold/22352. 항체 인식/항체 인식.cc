
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> before(row, vector<int>(col, 0));
    vector<vector<int>> after(row, vector<int>(col, 0));
    vector<vector<bool>> beforeVisited(row, vector<bool>(col, false));
    vector<vector<bool>> afterVisited(row, vector<bool>(col, false));
    // 백신 맞기 전 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> before[i][j];    
        }  
    }
    
    // 백신 맞은 후 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> after[i][j];
        }
    }
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool result = false;
    // 다른 부분은 한 구역 이하 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (before[i][j] != after[i][j]) {
            
                queue<pair<int, int>> q;
                q.push({i, j});
                beforeVisited[i][j] = true;
                int changeInt = after[i][j];
                vector<pair<int, int>> v;
                while (!q.empty()) {
                    auto s = q.front();
                    v.push_back(make_pair(s.first, s.second));
                    q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = s.first + dx[k];
                        int ny = s.second + dy[k];
                        
                        if (nx < 0 || ny < 0 || nx >= row || ny >= col || before[nx][ny] != before[s.first][s.second]) {
                            continue;
                        } 
                        
                        if (beforeVisited[nx][ny] == false) {
                            beforeVisited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                
                for (auto p : v) {
                    before[p.first][p.second] = changeInt;
                }
                
                for (int t = 0; t < row; t++) {
                    for (int u = 0; u < col; u++) {
                        if (before[t][u] != after[t][u]) {
                            result = true;
                        }
                    }
                }
                
                if (!result) {
                    cout << "YES";
                    exit(0);
                } else {
                    cout << "NO";
                    exit(0);
                }
            }
        }
    }
    
    cout << "YES";
    return 0;
}
