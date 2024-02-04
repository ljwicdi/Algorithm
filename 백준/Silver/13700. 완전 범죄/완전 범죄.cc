#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int N, S, D, F, B, K;
    cin >> N >> S >> D >> F >> B >> K;
    
    bool policeChk[N + 1] = {false, };
    bool visited[N + 1] = {false, };
    int p;
    for (int i = 0; i < K; i++) {
        cin >> p;
        policeChk[p] = true;
    }
    
    
    queue<pair<int, int>> q;
    q.push(make_pair(S, 0));
    visited[S] = true;
    
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.first == D) {
            result = s.second;
            break;
        }
        q.pop();
        
        // 우
        if (s.first + F <= N) {
            if (visited[s.first + F] == false) {
                if (policeChk[s.first + F] == false) {
                     visited[s.first + F] = true;
                    q.push(make_pair(s.first + F, s.second + 1));
                }
               
            }
        }
        
        // 좌
        if (s.first - B >= 1) {
            if (visited[s.first - B] == false) {
                if (policeChk[s.first - B] == false) {
                    visited[s.first - B] = true;
                    q.push(make_pair(s.first - B, s.second + 1));
                }
                
            }
        }
        
    }
    
    if (result == -1) {
        cout << "BUG FOUND";
    } else {
        cout << result;
    }
    
    return 0;
}
