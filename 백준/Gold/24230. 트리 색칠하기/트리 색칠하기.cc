#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> colors(N + 1, 0);
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> colors[i];
    }
    
    if (N == 1 && colors[1] != 0) {
        cout << "1";
        exit(0);
    }
    
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int result = 0;
    
    if (colors[1] != 0) {
        result = 1;
    }
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        for (auto k : v[s]) {
            if (visited[k] == false) {
                visited[k] = true;
                if (colors[s] != colors[k]) {
                    result++;
                } 
                q.push(k);
            }
        }
    }
    
    cout << result;
    return 0;
}
