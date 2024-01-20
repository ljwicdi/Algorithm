
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int A, K;
    cin >> A >> K;
    
    queue<pair<int, int>> q;
    q.push(make_pair(A, 0));
    set<int> mySet;
    mySet.insert(A);
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        if (s.first > K) {
            q.pop();
            continue;
        }
        if (s.first == K) {
            result = s.second;
            break;
        }
        q.pop();
        
        if (mySet.find(s.first + 1) == mySet.end()) {
            q.push(make_pair(s.first + 1, s.second + 1));
            mySet.insert(s.first + 1);
        }
        
        if (mySet.find(s.first * 2) == mySet.end()) {
            q.push(make_pair(s.first * 2, s.second + 1));
            mySet.insert(s.first * 2);
        }
    }
    
    cout << result;
    return 0;
}
