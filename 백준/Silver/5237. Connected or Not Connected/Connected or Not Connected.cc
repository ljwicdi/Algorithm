
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int n;
        cin >> n;
        vector<int> v[n];
        vector<bool> visited(n, false);
        
        int k;
        cin >> k;
        
        int a, b;
        for (int j = 0; j < k; j++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            for (auto p : v[s]) {
                if (visited[p] == false) {
                    visited[p] = true;
                    q.push(p);
                }
            }
        }
        
        bool isConnected = true;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false) {
                isConnected = false;
            }
        }
        
        if (!isConnected) {
            cout << "Not connected.\n";
        } else {
            cout << "Connected.\n";
        }
    }

    return 0;
}
