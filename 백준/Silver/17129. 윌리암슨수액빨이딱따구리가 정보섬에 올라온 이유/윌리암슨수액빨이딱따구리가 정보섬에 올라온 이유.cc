
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n];
    vector<bool> visited[n];
    int data;
    string str;
    int startX, startY;
    for (int i = 0; i < n; i++) {
        cin >> str;
        
        for (int j = 0; j < str.length(); j++) {
            v[i].push_back(str[j] - '0');
            visited[i].push_back(false);
            if (str[j] == '2') {
                startX = i;
                startY = j;
            }
        }
    }
    
    queue<node> q;
    node nd;
    nd.x = startX; nd.y = startY; nd.distance = 0;
    q.push(nd);
    visited[startX][startY] = true;
    
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int result = -1;
    int nx, ny;
    while (!q.empty()) {
        auto s = q.front();
        if (v[s.x][s.y] == 3 || v[s.x][s.y] == 4 || v[s.x][s.y] == 5) {
            result = s.distance;
            break;
        }
        q.pop();    
        
        for (int i = 0; i < 4; i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
            
            if (nx >= n || nx < 0 || ny >= m || ny < 0 || v[nx][ny] == 1) {
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
    
    if (result == -1) {
        cout << "NIE";
    } else {
        cout << "TAK\n";
        cout << result;
    }
    
    return 0;
}
