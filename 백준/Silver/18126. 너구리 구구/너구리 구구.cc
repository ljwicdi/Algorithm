#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    long long max = 0;
    
    int N;
    cin >> N;
    vector<pair<int, int>> v[N + 1];
    vector<bool> visited(N + 1, false);
    int a, b, weight;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> weight;
        v[a].push_back(make_pair(b, weight));
        v[b].push_back(make_pair(a, weight));
    }
    
    queue<pair<int, long long>> q;    // pair(node, distance)
    q.push(make_pair(1, 0));
    visited[1] = true;
    
    while (!q.empty()) {
        auto s = q.front();
        if (max < s.second) {
            max = s.second;
        }
        q.pop();
        
        for (auto k : v[s.first]) {
            if (visited[k.first] == false) {
                visited[k.first] = true;
                q.push(make_pair(k.first, s.second + k.second));
            }
        }
    }
    
    cout << max;
    return 0;
}
