#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    
    int start;
    vector<int> Ks;
    for (int i = 0; i < K; i++) {
        cin >> start;
        Ks.push_back(start);
    }
    
    int a, b;
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    int cnt[N + 1] = {0, };
    for (int i = 0; i < Ks.size(); i++) {
        queue<int> q;
        bool visited[N + 1] = {false, };
        q.push(Ks[i]);
        visited[Ks[i]] = true;
        cnt[Ks[i]]++;
        while (!q.empty()) {
            auto s = q.front();
            
            q.pop();
            
            for (auto p : v[s]) {
                if (visited[p] == false) {
                    visited[p] = true;
                    cnt[p]++;
                    q.push(p);
                }
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == K) {
            result++;
        }
    }
    
    cout << result;
    

    return 0;
}
