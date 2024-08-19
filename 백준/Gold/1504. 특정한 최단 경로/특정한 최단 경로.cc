#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, v1, v2;
int solve(vector<vector<pair<int, int>>> & graph, int start, int departure) {
    
    int distance[N + 1];
    for (int i = 0; i < N + 1; i++) {
        distance[i] = 2000000000;
    }
    distance[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        auto s = pq.top();
        pq.pop();
        
        if (distance[s.second] != s.first) continue;
        
        for (auto k : graph[s.second]) {
            if (distance[k.second] > distance[s.second] + k.first) {
                distance[k.second] = distance[s.second] + k.first;
                pq.push(make_pair(distance[k.second], k.second));
            }
        }
    }
    
    if (distance[departure] == 2000000000) {
        return -1;
    }
    
    return distance[departure];
}


int main() {
    
    int E;
    cin >> N >> E;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(cost, b));
        graph[b].push_back(make_pair(cost, a));
    }
    
    cin >> v1 >> v2;
    
    
    // 1 -> v1 -> v2 -> N
    int caseOne = 0;
    int result;
    result = solve(graph, 1, v1);
    
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    
    caseOne += result;
    
    result = solve(graph, v1, v2);
    
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    caseOne += result;
    
    result = solve(graph, v2, N);
    
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    caseOne += result;
    // 1 -> v2 -> v1 -> N
    
    int caseTwo = 0;
    result = solve(graph, 1, v2);
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    caseTwo += result;
    result = solve(graph, v2, v1);
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    caseTwo += result;
    result = solve(graph, v1, N);
    
    if (result == -1) {
        cout << "-1";
        return 0;
    }
    
    caseTwo += result;
    
    if (caseOne < caseTwo) {
        result = caseOne;
    } else {
        result = caseTwo;
    }
    
    cout << result;
    return 0;
}