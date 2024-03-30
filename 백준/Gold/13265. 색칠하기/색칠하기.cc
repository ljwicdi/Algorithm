#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    int n, m;
    for (int i = 0; i < testCase; i++) {
        cin >> n >> m;
        vector<int> v[n + 1];
        vector<bool> visited(n + 1, false);
        vector<int> color(n + 1, -1);
        int a, b;
        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        vector<int> start;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == false) {
                start.push_back(j);
                color[j] = 0;
                queue<int> q;
                q.push(j);
                visited[j] = true;
                while (!q.empty()) {
                    auto s = q.front();
                    q.pop();
            
                    for (auto k : v[s]) {
                        if (visited[k] == false) {
                            visited[k] = true;
                            if (color[s] == 0) {
                                color[k] = 1;
                            } else {
                                color[k] = 0;
                            }
                            q.push(k);
                        }
                    }
                }
            }
        }
        string result = "possible";
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            for (auto s : v[j]) {
                if (color[s] == color[j]) {
                    result = "impossible";
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        } 
        cout << result << "\n";
    }
    

    return 0;
}
