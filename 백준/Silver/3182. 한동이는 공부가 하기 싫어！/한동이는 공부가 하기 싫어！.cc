
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[1001] = {false, };

int dfs(int node, int prevVisitNum) {
    int currentVisitNum = prevVisitNum;
    visited[node] = true;
    for (auto s : v[node]) {
        if (visited[s] == false) {
            currentVisitNum = dfs(s, currentVisitNum + 1);
        }
    }
    
    return currentVisitNum;
}

int main()
{
    int N, data;
    cin >> N;
    
    
    for (int i = 1; i <= N; i++) {
        cin >> data;
        
        v[i].push_back(data);
    }
    
    int max = -1;
    int idx = 1;
    for (int i = 1; i <= N; i++) {
        
        for (int j = 1; j <= 1000; j++) {
            visited[j] = false;
        }
        
        int ithVisitNum = dfs(i, 1);
        if (ithVisitNum > max) {
            max = ithVisitNum;
            idx = i;
        }
    }
    
    cout << idx;

    return 0;
}
