#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    cout << fixed;
    cout.precision(10);
    
    int leafNodeCnt = 0, N, W;
    cin >> N >> W;
    
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    int a, b;
    for (int i = 0; i < N -  1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        bool flag = false;
        for (auto k : v[s]) {
            if (visited[k] == false) {
                visited[k] = true;
                q.push(k);
                flag = true;
            }
        }
        
        if (!flag) {
            leafNodeCnt++;
        }
    }
    
    double result = (double) W / leafNodeCnt;
    cout << result;
    
    
    return 0;
}
