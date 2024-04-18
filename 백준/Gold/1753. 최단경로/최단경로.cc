#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int V, E;
    cin >> V >> E;

    vector<int> dist(V + 1, 500000000); 
    vector<bool> visited(V + 1, false);
    map<pair<int, int>, int> myMap;
    map<int, vector<int>> connected; 
    // 시작 노드
    int start;
    cin >> start;
    dist[start] = 0;
    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        pair<int, int> key = make_pair(u, v);
        if (myMap.find(key) != myMap.end()) {
            if (myMap[key] <= w) continue; 
        }
        myMap[key] = w;
        if (connected.find(u) == connected.end()) {
            vector<int> temp;
            temp.push_back(v);
            connected[u] = temp;
        } else {
            connected[u].push_back(v);
        }
    }

    // <거리, 노드>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        auto s = pq.top();
        pq.pop();

        if (visited[s.second]) continue;

        visited[s.second] = true;
        int u = s.second;
        if (connected.find(u) == connected.end()) continue;
        vector<int> temp2 = connected[u];
        for (auto k : temp2) { 
            pair<int, int> temp = make_pair(u, k);
            if (myMap.find(temp) == myMap.end()) continue;
            int w = myMap[temp];
            if (dist[k] > dist[u] + w) {
                dist[k] = dist[u] + w;
                pq.push({dist[k], k});
            }
        }
    }

    for (int i = 1; i <= V; i++) { 
        if (dist[i] == 500000000) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
