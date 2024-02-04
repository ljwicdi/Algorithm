#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    // a -> b
    int a, b;
    cin >> a >> b;
    
    // 문자 수 : N, 쌍의 수 : M
    int N, M;
    cin >> N >> M;
    vector<int> v[N + 1];
    vector<bool> visited(N + 1, false);
    int num1, num2;
    for (int i = 0; i < M; i++) {
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    visited[a] = true;
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.first == b) {
            result = s.second;
            break;
        }
        q.pop();
        
        for (auto k : v[s.first]) {
            if (visited[k] == false) {
                visited[k] = true;
                q.push(make_pair(k, s.second + 1));
            }
        }
    }
    
    cout << result;
    return 0;
}
