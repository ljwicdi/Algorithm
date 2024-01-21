
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    int parent, child;
    cin >> n >> k;
    vector<int> v[n];
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child;
        v[parent].push_back(child);
        
    }
    
    vector<int> kV;
    int kNum;
    for (int i = 0; i < n; i++) {
        cin >> kNum;
        kV.push_back(kNum);
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    
    int result = 0;
    bool visited[n] = {false, };
    while (!q.empty()) {
        auto s = q.front();
        visited[s.first] = true;
        if (kV[s.first] == k) {
            result = s.second;
            break;
        }
        q.pop();
        for (auto t : v[s.first]) {
            if (visited[t] == false) {
                q.push(make_pair(t, s.second + 1));
            }
        }
    }
    
    cout << result;
    return 0;
}
