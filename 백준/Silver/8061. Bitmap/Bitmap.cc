
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int x;
    int y;
    int distance;
};
int main()
{
    int n, m;
    string str;
    cin >> n >> m;
    vector<int> v[n];
    vector<bool> visited[n];
    vector<int> result[n];
    queue<node> q;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            visited[i].push_back(false);
            result[i].push_back(0);
            if (str[j] == '1') {
                v[i].push_back(1);
                node nd;
                nd.x = i;
                nd.y = j;
                nd.distance = 0;
                q.push(nd);
                visited[i][j] = true;
            } else {
                v[i].push_back(0);
            }
            
        }
    }
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    while (!q.empty()) {
        auto s = q.front();
        if (v[s.x][s.y] == 0) {
            result[s.x][s.y] = s.distance;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == 1) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
                node nd;
                nd.x = nx;
                nd.y = ny;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
