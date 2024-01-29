
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int N, K;
vector<int> v[101];
vector<bool> visited;
int dfs(int node, int visitedNum) {
    visited[node] = true;
    int temp = visitedNum;
    for (auto s : v[node]) {
        if (!visited[s]) {
            temp = dfs(s, temp + 1);
        }
    }
    return temp;
}
int main()
{
    // bfs -> 이동거리가 6보다 큰 노드가 나오면 big world
    // 모든 노드에 대해 출발점으로 체크
    
    
    cin >> N >> K;
    
    
    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bool isSmallWorld;
    int result;
    
    for (int i = 0; i <= N; i++) {
        visited.push_back(false);
    }
    
    for (int i = 1; i <= N; i++) {
        
        for (int j = 0; j <= N; j++) {
            visited[j] = false;
        }
        
        int a = dfs(i, 1);
        
        if (a != N) {
            isSmallWorld = false;
            break;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, 0));
        set<int> mySet;
        mySet.insert(i);
        isSmallWorld = true;
        result = 0;
        while (!q.empty()) {
            auto s = q.front();
            if (s.second > 6) {
                result = 1;
                break;
            }
           
            q.pop();
            for (auto k : v[s.first]) {
                if (mySet.find(k) == mySet.end()) {
                    mySet.insert(k);
                    q.push(make_pair(k, s.second + 1));
                }
            }
        } 
        
        if (result == 1) {
            isSmallWorld = false;
            break;
        }
        
    }
    
    if (isSmallWorld) {
        cout << "Small World!";
    } else {
        cout << "Big World!";
    }

    return 0;
}
