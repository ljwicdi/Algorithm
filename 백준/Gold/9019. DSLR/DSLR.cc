#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int A, B;
        cin >> A >> B;
        bool visited[10000] = {false, };
        // A -> B
        queue<pair<int, string>> q;
        q.push(make_pair(A, ""));
        visited[A] = true;
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            if (s.first == B) {
                cout << s.second << "\n";
                break;
            }
            
            if (s.first * 2 > 9999) {
                if (!visited[(s.first * 2) % 10000]) {
                    q.push(make_pair((s.first * 2) % 10000, s.second + "D"));
                    visited[(s.first * 2) % 10000] = true;
                    
                }
            } else {
                if (!visited[s.first * 2]) {
                    q.push(make_pair(s.first * 2, s.second + "D"));
                    visited[s.first * 2] = true;
                }
            }
            
            if (s.first == 0) {
                if (!visited[9999]) {
                    q.push(make_pair(9999, s.second + "S"));
                    visited[9999] = true;
                }
            } else {
                if (!visited[s.first - 1]) {
                    q.push(make_pair(s.first - 1, s.second + "S"));
                    visited[s.first - 1] = true;
                }
            }
            
            // 왼편으로 회전
            int result = (s.first % 1000) * 10 + s.first / 1000;
            
            if (!visited[result]) {
                q.push(make_pair(result, s.second + "L"));
                visited[result] = true;
            }
            
            
            // 오른쪽으로 회전
            result = (s.first % 10) * 1000 + s.first / 10;
            
            if (!visited[result]) {
                q.push(make_pair(result, s.second + "R"));
                visited[result] = true;
            }
            
        }
    }
    return 0;
}