#include <iostream>
#include <vector>
#define INF 2100000000
using namespace std;
int N, M, W;
bool isNegativeCycle(vector<vector<pair<int, int>>> & graph) {
    
    int d[N + 1] = {INF, };
    d[1] = 0;
    
    for (int i = 0; i < N; i++) {
        
        for (int j = 1; j <= N; j++) {
            for (auto s : graph[j]) {
                if (d[s.first] == INF) {
                    continue;
                }
                
                if (d[s.first] > d[j] + s.second) {
                    d[s.first] = d[j] + s.second;
                    
                    if (i == N - 1) return true;
                }
            }
        }
    }
    
    return false;
    
}

int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> N >> M >> W;
        vector<vector<pair<int, int>>> graph(N + 1);
        for (int j = 0; j < M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back(make_pair(E, T));
            graph[E].push_back(make_pair(S, T));
        }
        
        for (int j = 0; j < W; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            graph[S].push_back(make_pair(E, (-1) * T));
        }
        
        if (isNegativeCycle(graph)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}