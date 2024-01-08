
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first < b.first) {
        return false;
    } else {    // 거리가 같다면 헛간 번호가 작은 순으로 
        if (a.second < b.second) {
            return true;
        } else {
            return false;
        }
    }
}
int main() {
    int N, M;
    int a, b;
   
    vector<bool> visited;

    cin >> N >> M;
    vector<int> v[N + 1];
    for (int i = 0; i < N + 1; i++) {
        visited.push_back(false);
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    set<int> mySet;
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));  // 1부터 찾음
    mySet.insert(1);
    // bfs
    vector<pair<int, int>> result;
    while (!q.empty()) {
        auto s = q.front();
        
        result.push_back(make_pair(s.second, s.first)); // pair(거리, 헛간 번호)
        
        visited[s.first] = true;
        q.pop();
        
        for (auto k : v[s.first]) {
            if (!visited[k] && mySet.find(k) == mySet.end()) {
                q.push(make_pair(k, s.second + 1));
                mySet.insert(k);
            } 
        }
            
    }
    
    // 헛간의 번호가 가장 적은 순으로 출력
    sort(result.begin(), result.end(), comp);
    int cnt = 1;
    for (int i = 1; i < result.size(); i++) {
        if (result[i].first == result[0].first) {
            cnt++;
        }
    }
    
    cout << result[0].second << " " << result[0].first << " " << cnt;

    return 0;
}
