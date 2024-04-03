
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n + 1);
    int city1, city2;
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2;
        v[city1].insert(city2);
        v[city2].insert(city1);
    }
    
    int q, a, i, j;
    cin >> q;
    for (int p = 0; p < q; p++) {
        cin >> a >> i >> j;
        // 도로 생성 
        if (a == 1) {
           v[i].insert(j);
           v[j].insert(i);
           // 도로제거  
        } else if (a == 2) {
            v[i].erase(j);
            v[j].erase(i);
        }
        
        // 계획을 완수하고 bfs
        int result[n + 1];
        for (int t = 0; t < n + 1; t++) {
            result[t] = -1;
        }
        bool visited[n + 1] = {false, };
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty()) {
            auto s = q.front();
            result[s.first] = s.second;
            q.pop();
            
            for (auto k : v[s.first]) {
                if (visited[k] == false) {
                    visited[k] = true;
                    q.push({k, s.second + 1});
                }
            }
        }
        
        for (int o = 1; o < n + 1; o++) {
            cout << result[o] << " ";
        }
        cout << "\n";
    }
    return 0;
}
