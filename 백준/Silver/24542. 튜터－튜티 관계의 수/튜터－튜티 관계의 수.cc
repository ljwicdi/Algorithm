
#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;
vector<int> v[200001];
long long dfs(int node, long long cnt) {
    visited[node] = true;
    long long currentNum = cnt;
    for (auto s : v[node]) {
        if (visited[s] == false) {
            currentNum = dfs(s, currentNum + 1);
        }
    }
    return currentNum;
}   

int main()
{
    int N, M;
    cin >> N >> M;
    
    
  
    for (int i = 0; i <= N; i++) {
        visited.push_back(false);
    }
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    vector<long long> result;
    
    for (int i = 1; i <= N; i++) {
        long long visitedCnt = 0;
        if (visited[i] == false) {
            visitedCnt = dfs(i, 1);
        }
        if (visitedCnt != 0) {
            result.push_back(visitedCnt);
        }
    }
    
    long long gob = 1;
    
    for (int i = 0; i < result.size(); i++) {
        gob = gob * result[i];
        gob = gob % 1000000007;
    }
    
    cout << gob;
    

    return 0;
}
