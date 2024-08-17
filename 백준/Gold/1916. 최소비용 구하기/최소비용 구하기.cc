#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
void solve(int start, vector<vector<pair<int, int>>> & graph, int end) {
    
    long long distance[N + 1];
    for (int i = 1; i <= N; i++) {
        distance[i] = 10000000000000;
    }
    
    distance[start] = 0;
    // pair<거리, 노드> 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        auto s = pq.top();
        pq.pop();
        
        if (distance[s.second] != s.first) continue;
        
        for (auto k : graph[s.second]) {
            if (distance[k.first] > distance[s.second] + k.second) {
                distance[k.first] = distance[s.second] + k.second;
                pq.push(make_pair(distance[k.first], k.first));
            }
        }
    }
    
    cout << distance[end];
}

int main() {
    
    int M, start, end;
    cin >> N;
    cin >> M;
    
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
    }
    
    cin >> start >> end;
    
    solve(start, graph, end);
    
    return 0;
}