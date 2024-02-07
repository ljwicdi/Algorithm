
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    long total = 0;
    int N;
    cin >> N;
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);  
    }
    
    queue<pair<int, int>> q;    // pair(node, distance)
    q.push(make_pair(1, 0));    // 1번 노드가 루트 
    visited[1] = true;
    
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        int chk = 0;
        for (auto k : v[s.first]) {
            if (visited[k] == false) {
                chk++;
                visited[k] = true;
                q.push(make_pair(k, s.second + 1));
            }
        }
        
        if (chk == 0) {
            total = total + s.second;
        }
    }
    
  
    
    if (total % 2 == 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}
