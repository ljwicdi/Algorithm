#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int directionTo[1001];
int reverseTo[1001];

void solve(vector<vector<pair<int, int>>> & edge, int X, bool isDirection) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, X)); // 거리, 정점
    
    while (!pq.empty()) {
        auto node = pq.top();
        
        pq.pop();
        
        if (isDirection) {
            if (directionTo[node.second] != node.first) {
                continue;
            }
        } else {
            if (reverseTo[node.second] != node.first) {
                continue;
            }
        }
        
        for (auto k : edge[node.second]) {
            if (isDirection) {
                if (directionTo[k.first] > k.second + node.first) {
                    directionTo[k.first] = k.second + node.first;
                    pq.push(make_pair(k.second + node.first, k.first));
                }
            } else {
                if (reverseTo[k.first] > k.second + node.first) {
                    reverseTo[k.first] = k.second + node.first;
                    pq.push(make_pair(k.second + node.first, k.first));
                }
            }
        }
    }
}

int main() {
    fill(directionTo, directionTo + 1001, 1000000000);
    fill(reverseTo, reverseTo + 1001, 1000000000);

    int N, M, X;
    cin >> N >> M >> X;
    
    vector<vector<pair<int, int>>> edge(N + 1);
    vector<vector<pair<int, int>>> reverseEdge(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[a].push_back(make_pair(b, cost));
        reverseEdge[b].push_back(make_pair(a, cost));
    }
    
    directionTo[X] = 0;
    reverseTo[X] = 0;
    
    // 기존 그래프에서의 X마을 시작 다익스트라 (돌아오는 길)
    // 역방향 그래프에서의 X마을 시작 다다익스트라 (가는 길)
    solve(edge, X, true);
    solve(reverseEdge, X, false);
    
    int ma = -1;
    for (int i = 1; i <= N; i++) {
        if (i != X) {
            if (ma < directionTo[i] + reverseTo[i]) {
                ma = directionTo[i] + reverseTo[i];
            }
        }
    }
    
    cout << ma;
    
    return 0;
}
