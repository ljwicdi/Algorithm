
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int chk;
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> v[N];
    vector<bool> visited[N];
    
    int data;
    int zeroChk = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 0 : 자랄 수 있음, 1 : 자랄 수 없음
            cin >> data;
            if (data == 0) {
                zeroChk = 1;
            }
            v[i].push_back(data);
            visited[i].push_back(false);
        }
    }
    
    if (zeroChk == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int i = 0, j = 0;
    while (1) {
        while (1) {
            if (v[i][j] == 0 && visited[i][j] == false) {
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
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int nx, ny;
        chk = K - 1;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
           
            for (int k = 0; k < 4; k++) {
                nx = s.first + dx[k];
                ny = s.second + dy[k];
                
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || v[nx][ny] == 1 || chk == 0) {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    chk--;
                }
            }
        }
        M = M - 1;
    }
    
    if (M < 0) {
        cout << "IMPOSSIBLE";
    } else{
        cout << "POSSIBLE\n";
        cout << M;
    }
    return 0;
}
