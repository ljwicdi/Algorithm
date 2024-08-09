#include <iostream>
#define INF 2000000000
using namespace std;
int main() {
    
    int n, m;
    cin >> n >> m;
    
    long long graph[n + 1][n + 1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
            if (i == j) graph[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        
        if (graph[a][b] != 0) {
            if (graph[a][b] > cost) {
                graph[a][b] = cost;        
            }
        } else {
            graph[a][b] = cost;
        }
        
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << graph[i][j] << " ";    
            }
        }
        cout << "\n";
    }

    return 0;
}