#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int R, C, N;
    cin >> R >> C >> N;
    
    vector<char> v[R];
    char data;

    int sec = 1;
    queue<pair<int, int>> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> data;
            v[i].push_back(data);

            if (data == 'O') {
                q.push(make_pair(i, j));
            }
        }
    }

    if (N == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << v[i][j];
            }
            cout << "\n";
        }
        return 0;
    }
    
    if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << "O";
            }
            cout << "\n";
        }
        return 0;
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 초기화 추가
    vector<char> result1[R];
    vector<char> result2[R];
    for (int i = 0; i < R; i++) {
        result1[i] = vector<char>(C, 'O');
        result2[i] = vector<char>(C, 'O');
    }

    queue<pair<int, int>> temp;
    int one = 0, two = 0;
    while (1) {
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        
        set<pair<int, int>> t;
        while (!q.empty()) {
            auto s = q.front();
            temp.push(make_pair(s.first, s.second));
            visited[s.first][s.second] = true;
            t.insert(make_pair(s.first, s.second));
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = s.first + dx[i];
                int ny = s.second + dy[i];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
                    temp.push(make_pair(nx, ny));
                    t.insert(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }

        sec += 2;

        if (sec % 4 == 1) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (t.find(make_pair(i, j)) == t.end()) {
                        result2[i][j] = 'O';
                    } else {
                        result2[i][j] = '.';
                    }
                }
            }
            two = 1;
        } else if (sec % 4 == 3) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (t.find(make_pair(i, j)) == t.end()) {
                        result1[i][j] = 'O';
                        q.push(make_pair(i, j));
                    } else{
                        result1[i][j] = '.';
                    }
                }
            }
            one = 1;
        }
        if (one == 1 && two == 1) {
            break;
        }
    }

    if (N % 4 == 3) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << result1[i][j];
            }
            cout << "\n";
        }
    }

    if (N % 4 == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << result2[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
