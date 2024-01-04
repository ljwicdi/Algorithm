
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    int result = 0;
    cin >> n;
    
    int Q1, Q2;
    cin >> Q1 >> Q2;
    
    int m;
    cin >> m;
    
    vector<int> edge[n + 1]; // 1 ~ n
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    
    queue< pair<int, int> > q;
    
    vector<bool> visited;
    for (int i = 0; i < n + 1; i++) {
        visited.push_back(false);
    }
    
    q.push(make_pair(Q1, 0));
    
    
    while (!q.empty()) {
        auto s = q.front();
        visited[s.first] = true;
        q.pop();
        
        if (s.first == Q2) {
            result = s.second;
            break;
        }
        for (auto k : edge[s.first]) {
            if (visited[k] == false) {
                q.push(make_pair(k, s.second + 1));
            }
        }
    }
    
    if (result == 0) {
        cout << "-1";
    } else {
        cout << result;
    }
    
    return 0;
}
