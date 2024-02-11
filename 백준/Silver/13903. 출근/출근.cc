
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
    int r, c;
    cin >> r >> c;
    vector<int> v[r];
    vector<pair<int, int>> sero;
    vector<bool> visited[r];
    int data;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> data;
            v[i].push_back(data);
            visited[i].push_back(false);
            if (i == 0) {
                if (data == 1) {
                    sero.push_back(make_pair(i, j));
                }
            }
        }
    }
    
    int ruleNumber;
    cin >> ruleNumber;
    
    vector<int> dx;
    vector<int> dy;
    int x, y;
    for (int i = 0; i < ruleNumber; i++) {
        cin >> x >> y;
        dx.push_back(x);
        dy.push_back(y);
    }
    
    // multisource bfs 
    queue<node> q;
    for (auto s : sero) {
        visited[s.first][s.second] = true;
        node nd;
        nd.x = s.first;
        nd.y = s.second;
        nd.distance = 0;
        q.push(nd);
    }
    int result = -1;
    int nx, ny;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.x == r - 1) {
            result = s.distance;
            break;
        }
        
        q.pop();
        
        
        for (int i = 0; i < dx.size(); i++) {
            nx = s.x + dx[i];
            ny = s.y + dy[i];
            
            if (nx >= r || nx < 0 || ny >= c || ny < 0 || v[nx][ny] == 0) {
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
    
    cout << result;
    return 0;
}
