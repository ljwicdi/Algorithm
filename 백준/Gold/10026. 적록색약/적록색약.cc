
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N, '-'));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    // 적록색약 (그린 = 레드) 이 본 맵 
    vector<vector<char>> changedMap(N, vector<char>(N, '-'));
    vector<vector<bool>> visited2(N, vector<bool>(N, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            changedMap[i][j] = map[i][j];
            if (map[i][j] == 'G' || map[i][j] == 'R') {
                changedMap[i][j] = 'S';
            }
        }
    }
    
    // 일반인 
    int i = 0, j = 0;
    int cnt1 = 0;
    while (1) {
        while(1) {
            if (visited[i][j] == false) {
                break;
            }
            j++;
            if (j == N) {
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
        
        cnt1++;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        char criteria = map[i][j]; 
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = s.first + dx[k];
                int ny = s.second + dy[k];
                
                if (nx < 0 || ny < 0 || nx == N || ny == N || map[nx][ny] != criteria) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    i = 0, j = 0;
    int cnt2 = 0;
    while (1) {
        while(1) {
            if (visited2[i][j] == false) {
                break;
            }
            j++;
            if (j == N) {
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
        
        cnt2++;
        queue<pair<int, int>> q2;
        q2.push(make_pair(i, j));
        visited2[i][j] = true;
        char criteria = changedMap[i][j]; 
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q2.empty()) {
            auto s = q2.front();
            q2.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = s.first + dx[k];
                int ny = s.second + dy[k];
                
                if (nx < 0 || ny < 0 || nx == N || ny == N || changedMap[nx][ny] != criteria) {
                    continue;
                }
                
                if (visited2[nx][ny] == false) {
                    visited2[nx][ny] = true;
                    q2.push(make_pair(nx, ny));
                }
            }
        }
    }
    cout << cnt1 << " " << cnt2;

    return 0;
}
