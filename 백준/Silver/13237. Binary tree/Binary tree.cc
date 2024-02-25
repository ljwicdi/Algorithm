
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool comp (pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else {
        return false;
    }
}

int main() {
    
    int n;
    cin >> n;
    int parent, root;
    vector<int> v[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> parent;
        if (parent == -1) {
            root = i;
            continue;
        }
        v[parent].push_back(i);
        
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(root, 0));
    
    vector<pair<int, int>> result;
    while (!q.empty()) {
        auto s = q.front();
        result.push_back(make_pair(s.first, s.second));
        q.pop();
        
        for (auto k : v[s.first]) {
            q.push(make_pair(k, s.second + 1));
        }
    }
    
    sort(result.begin(), result.end(), comp);
    
    for (auto s : result) {
        cout << s.second << "\n";
    }
    return 0;
}
