#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    
    int N, M;
    cin >> N >> M;
    vector<int> v[N + 1];
    int indegree[N + 1] = {0, };
    vector<int> result;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    
    for (int i = 1; i < N + 1; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (auto s : v[node]) {
            indegree[s]--;
            if (indegree[s] == 0) {
                q.push(s);
            }
        }
    }
    
    for (auto s : result) {
        cout << s << " ";
    }

    return 0;
}
