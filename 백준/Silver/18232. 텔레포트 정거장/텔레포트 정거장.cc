
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int S, E;
    cin >> S >> E;
    
    vector<int> v[N + 1];
    for (int i = 0; i < N + 1; i++) {
        v[i].push_back(0);
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    set<int> mySet;
    queue<pair<int, int>> q;
    q.push(make_pair(S, 0));
    mySet.insert(S);
    int result = 0;
    
    while (!q.empty()) {
        auto s = q.front();
        if (s.first == E) {
            result = s.second;
            break;
        }
        q.pop();
        
        if (mySet.find(s.first + 1) == mySet.end()) {
            if (s.first + 1 <= N) {
                q.push(make_pair(s.first + 1, s.second + 1));
                mySet.insert(s.first + 1);
            }
        }
        
        if (mySet.find(s.first - 1) == mySet.end()) {
            if (s.first - 1 >= 0) {
                q.push(make_pair(s.first - 1, s.second + 1));
                mySet.insert(s.first - 1);
            }
        }
        
        if (v[s.first].size() != 1) {
            for (int j = 1; j < v[s.first].size(); j++) {
                if (mySet.find(v[s.first][j]) == mySet.end()) {
                    q.push(make_pair(v[s.first][j], s.second + 1));
                    mySet.insert(v[s.first][j]);
                }
            }
            
        }
        
    }
    
    
    cout << result;
    return 0;
}
