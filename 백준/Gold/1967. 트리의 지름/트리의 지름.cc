#include <iostream>
#include <vector>
using namespace std;
int maxDistance = -1;
int node = 1;

void dfs(int cost, int currentNode, vector<bool> & visited, vector<vector<pair<int, int>>> & graph) {
    
    visited[currentNode] = true;
    int bottom = 0;
    for (auto s : graph[currentNode]) {
        if (!visited[s.first]) {
            bottom++;
            dfs(cost + s.second, s.first, visited, graph);
        }
    }
    
    if (bottom == 0) {
        if (maxDistance < cost) {
            maxDistance = cost;
            node = currentNode;
        }
    }
}

int main() {
    
    // 트리의 지름 -> dfs 2번
    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }
    
    vector<bool> visited(n + 1, false);
    
    dfs(0, 1, visited, graph);
    
    for (int i = 0; i < n + 1; i++) {
        visited[i] = false;
    }
    
    dfs(0, node, visited, graph);
    
    cout << maxDistance;

    return 0;
}