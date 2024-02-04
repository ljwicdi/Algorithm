#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> RGB[N];
    vector<int> v[N];
    int data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3 * M; j+=3) {
            for (int k = 0; k < 3; k++) {
                cin >> data;
                RGB[i].push_back(data);
            }
        }
    }
    
    int T;
    cin >> T;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3 * M; j+=3) {
            if ((RGB[i][j] + RGB[i][j + 1] + RGB[i][j + 2]) / 3.0 >= T) {
                v[i].push_back(1);
            } else {
                v[i].push_back(0);
            }
        }
    }
    
    vector<vector<bool>> visited (N, vector<bool> (M, false));
    
    int i = 0, j = 0;
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = 0;
    int nx, ny;
    while (1) {
        while (1) {
            if (visited[i][j] == false && v[i][j] == 1) {
                break;
            }
            
            j++;
            
            if (j == M) {
                j = 0;
                i++;
            }
            if (i == N) {
                break;
            }
        }
        
        if (i == N) {
            break;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        result++;
        while (!q.empty()) {
            auto s = q.front();
            
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                nx = s.first + dx[k];
                ny = s.second + dy[k];
                
                if (nx >= N || nx < 0 || ny < 0 || ny >= M) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    if (v[nx][ny] == 1) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
