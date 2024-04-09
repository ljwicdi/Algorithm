#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, S, P;
    cin >> N >> S >> P;
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<pair<int, int>> q;
    q.push({P, 0});
    
    int cnt = 0;
    int baseCnt = 0;
    while (!q.empty()) {
        auto s = q.front();
        if (s.first <= S) {
            cnt++;
            baseCnt += s.second;
            if (cnt == 2) {
                break;
            }
            q.pop();
            continue;
        }
        
        q.pop();
        
        for (auto k : v[s.first]) {
            if (visited[k] == false) {
                visited[k] = true;
                q.push({k, s.second + 1});
            }
        }
    }
    
    
    cout << N - baseCnt - 1;
    return 0;
}
