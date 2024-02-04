#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100001];
bool visited[100001] = {false, };
int dfs(int node, int cnt) {
    int currentCnt = cnt;
    visited[node] = true;
    for (auto s : v[node]) {
        if (visited[s] == false) {
            currentCnt = dfs(s, currentCnt + 1);
        }
    }
    
    return currentCnt;
}


int main() {
    
    int N, M;
    cin >> N >> M;
    
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    int X;
    cin >> X;
    
    int result = dfs(X, 0);
    cout << result;
    return 0;
}
