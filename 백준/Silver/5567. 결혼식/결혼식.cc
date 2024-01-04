
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];
    bool visited[n + 1];
    for (int i = 0; i < n + 1; i++) {
        visited[i] = false;
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue< pair<int, int> > q;
    q.push(make_pair(1, 0));
    int result = 0;
    set<int> mySet;
    mySet.insert(1);
    while (!q.empty()) {
        auto s = q.front();
        if (s.second == 1 || s.second == 2) {
            result++;
        }
        visited[s.first] = true;
        q.pop();
        
        for (auto k : v[s.first]) {
            if (visited[k] == false) {
                if (mySet.find(k) == mySet.end()) {
                    q.push(make_pair(k, s.second + 1));
                    mySet.insert(k);
                }
                
            }
        }
        
    }
    
    cout << result;
    
    return 0;
}
