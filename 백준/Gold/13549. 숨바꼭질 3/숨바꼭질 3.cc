#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<bool> visited(100001, false);
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    visited[N] = true;
    
    int result = 999999;
    while (!q.empty()) {
        auto s = q.front();
        if (s.first == K) {
            if (result > s.second) {
                result = s.second;
            }   
        }
        
        q.pop();
        
        if (s.first * 2 <= 100000) {
            if (visited[s.first * 2] == false) {
                visited[s.first * 2] = true;
                q.push({s.first * 2, s.second});
            }
        }
        if (s.first - 1 >= 0) {
            if (visited[s.first - 1] == false) {
                visited[s.first - 1] = true;
                q.push({s.first - 1, s.second + 1});
            }
        }
        
        if (s.first + 1 <= 100000) {
            if (visited[s.first + 1] == false) {
                visited[s.first + 1] = true;
                q.push({s.first + 1, s.second + 1});
            }
        }
    }
    cout << result;
    return 0;
}
