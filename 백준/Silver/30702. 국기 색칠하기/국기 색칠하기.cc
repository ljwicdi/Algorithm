
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    vector<char> before[row], after[row];
    vector<bool> visited[row];
    vector<char> result[row];
    string str;
    for (int i = 0; i < row; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            before[i].push_back(str[j]);
            visited[i].push_back(false);
            result[i].push_back(str[j]);
        }
    }
    
    for (int i = 0; i < row; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            after[i].push_back(str[j]);
        }
    }
    
    int i = 0, j = 0;
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    // 다음 좌표
    int nx, ny;
    while (1) {
        while (1) {
            if (visited[i][j] == false) {
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
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        char changeChar = after[i][j];
        char beforeChar = before[i][j];
        while (!q.empty()) {
            auto s = q.front();
            // 해당 색으로 바꿈
            result[s.first][s.second] = changeChar;
            q.pop();
        
            for (int i = 0; i < 4; i++) {
                nx = s.first + dx[i];
                ny = s.second + dy[i];
            
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
                    continue;
                }
            
                if (visited[nx][ny] == false && before[nx][ny] == beforeChar) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            
            }
        }
    }

    bool same = true;
    for (int i = 0; i < row; i++) {
        
        for (int j = 0; j < col; j++) {
            if (after[i][j] != result[i][j]) {
                same = false;
                break;
            }
            
        }
        if (same == false) {
            break;
        }
    }
    
    if (same) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
