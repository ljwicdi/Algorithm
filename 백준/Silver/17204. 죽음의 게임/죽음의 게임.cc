
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int N, K, data;
    cin >> N >> K;
    vector<int> v[N];
    for (int i = 0; i < N; i++) {
        cin >> data;
        v[i].push_back(data);
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    int result = -1;
    set<int> mySet;
    mySet.insert(0);
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.first == K) {
            result = s.second;
            break;
        }
        q.pop();
        if (mySet.find(v[s.first][0]) == mySet.end()) {
            q.push(make_pair(v[s.first][0], s.second + 1));
            mySet.insert(v[s.first][0]);
        }
        
    }
    
    cout << result;
    return 0;
}
