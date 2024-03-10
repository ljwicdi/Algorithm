#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    
    for (int i = 0; i < testCase; i++) {
        int R, C;
        cin >> R >> C;
        vector<int> result;
        string str;
        vector<vector<int>> v(R, vector<int>(C, 0));
        
        // 초기 그리드 상태 입력
        for (int j = 0; j < R; j++) {
            cin >> str;
            for (int k = 0; k < str.length(); k++) {
                if (str[k] == '1') {
                    v[j][k] = 1;
                }
            }
        }
        
      
        // 작업의 수 
        int N;
        cin >> N;
        
        for (int j = 0; j < N; j++) {
            if (j == 0) cin.ignore();
            getline(cin, str);
           
            if (str[0] == 'M') {
                int index = 2;
                string su = "";
                while (str[index] != ' ') {
                    su += str[index];
                    index++;
                }
                int row = stoi(su);
                su = "";
                index++;
                while (str[index] != ' ') {
                    su += str[index];
                    index++;
                }
                int col = stoi(su);
                index++;
                int changeTo = str[index] - '0';
                v[row][col] = changeTo;
            } else {
                
                vector<vector<bool>> visited(R, vector<bool>(C, false));
                int x = 0, y = 0;
                int cnt = 0;
                while (1) {
                    while (1) {
                        if (v[x][y] == 1 && visited[x][y] == false) {
                            break;
                        }
                        y++;
                        if (y == C) {
                            y = 0;
                            x++;
                        }
                        if (x == R) {
                            break;
                        }
                    }
                    if (x == R) {
                        break;
                    }
                    visited[x][y] = true;
                    queue<pair<int, int>> q;
                    q.push(make_pair(x, y));
                    int dx[4] = {-1, 0, 1, 0};
                    int dy[4] = {0, 1, 0, -1};
                    cnt++;
                    while (!q.empty()) {
                        auto s = q.front();
                        q.pop();
                        
                        for (int p = 0; p < 4; p++) {
                            int nx = s.first + dx[p];
                            int ny = s.second + dy[p];
                            
                            if (nx < 0 || nx == R || ny < 0 || ny == C || v[nx][ny] == 0) {
                                continue;
                            }  
                            
                            if (visited[nx][ny] == false) {
                                visited[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                                
                            }
                        }
                    }
                    
                }
                result.push_back(cnt);
            }
        }
        
        cout << "Case #" << i + 1 << ":\n";
        for(int t = 0; t < result.size(); t++) {
            cout << result[t] << "\n";
        }
    }

    return 0;
}
