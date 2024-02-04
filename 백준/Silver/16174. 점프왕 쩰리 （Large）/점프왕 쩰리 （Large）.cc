#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> v[N];
    vector<vector<bool>> visited (N, vector<bool> (N, false));
    int data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    string result = "Hing";
    // 동, 남
    
    int nx, ny;
    while (!q.empty()) {
        auto s = q.front();
        if (v[s.first][s.second] == -1) {
            result = "HaruHaru";
            break;
        }
        q.pop();
        
        // 동쪽
        nx = s.first;
        ny = s.second + v[s.first][s.second];
        
        if (ny <= N - 1) {
            if (visited[nx][ny] == false) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
        
        // 남쪽
        nx = s.first + v[s.first][s.second];
        ny = s.second;
        
        if (nx <= N - 1) {
            if (visited[nx][ny] == false) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    
    cout << result;
    return 0;
}
