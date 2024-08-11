#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int V;
    cin >> V;
    vector<vector<pair<int, int>>> graph(V + 1);
    vector<bool> visited(V + 1);
    for (int i = 0; i < V; i++) {
        int startNode, endNode, cost;
        
        cin >> startNode;
        
        while (1) {
            cin >> endNode;
            
            if (endNode == -1) {
                break;
            }
            
            cin >> cost;
            
            graph[startNode].push_back(make_pair(endNode, cost));
        }
    }

    visited[1] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    int currentMax = -1;
    int maxNode = 1;
    while (!q.empty()) {
        auto s = q.front();
        if (currentMax < s.second) {
            currentMax = s.second;
            maxNode = s.first;
        }
        q.pop();
        
        for (auto k : graph[s.first]) {
            if (!visited[k.first]) {
                visited[k.first] = true;
                q.push(make_pair(k.first, s.second + k.second));
            }
        }
    }
    
    for (int i = 0; i < V + 1; i++) {
        visited[i] = false;
    } 
    
    visited[maxNode] = true;
    queue<pair<int, int>> q2;
    q2.push(make_pair(maxNode, 0));
    currentMax = -1;
    
    while (!q2.empty()) {
        auto s = q2.front();
        if (currentMax < s.second) {
            currentMax = s.second;
        }
        q2.pop();
        
        for (auto k : graph[s.first]) {
            if (!visited[k.first]) {
                visited[k.first] = true;
                q2.push(make_pair(k.first, s.second + k.second));
            }
        }
    }
    
    cout << currentMax;
    
    return 0;
}