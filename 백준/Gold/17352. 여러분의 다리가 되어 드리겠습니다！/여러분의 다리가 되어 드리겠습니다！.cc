#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    int a, b;
    for (int i = 0; i < N - 2; i++) {
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
        
        for (auto k : v[s]) {
            if (!visited[k]) {
                visited[k] = true;
                q.push(k);
            }
        }
    }
    int result;
    for (int i = 2; i <= N; i++) {
        if (!visited[i]) {
            result = i;
            break;
        }
    }
    
    cout << 1 << " " << result;
    
    return 0;
}
