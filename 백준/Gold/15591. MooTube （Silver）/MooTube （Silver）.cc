
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int result;

void dfs(int k, int node, vector<vector<pair<int, int>>> & graph, vector<bool> & visited, int currentMin) {
    
    for (auto s : graph[node]) {
        if (visited[s.first] == false) {
            visited[s.first] = true;
            if (currentMin > s.second) {
                if (k <= s.second) {
                    result++;
                }
                dfs(k, s.first, graph, visited, s.second);
                
            } else {
                if (k <= currentMin) {
                    result++;
                }
                dfs(k, s.first, graph, visited, currentMin);
            }
        }
    }
}
int main() {
    
    int N, Q;
    cin >> N >> Q;
    vector<vector<pair<int, int>>> graph(N + 1);
    int p, q, r;
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;
        graph[p].push_back(make_pair(q, r));
        graph[q].push_back(make_pair(p, r));
    }
    
    int k, v;
    for (int i = 0; i < Q; i++) {
        result = 0;
        // 현재 v라는 동영상을 보고 있는데 유사도가 k이상인 노드들의 개수는? 
        cin >> k >> v;
        vector<bool> visited(N + 1, false);
        visited[v] = true;
        dfs(k, v, graph, visited, 2000000000);
        cout << result << "\n";
    }
    return 0;
}
