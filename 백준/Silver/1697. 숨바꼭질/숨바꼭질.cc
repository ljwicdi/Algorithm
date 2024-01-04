
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main() {
    
    int N, K;
    set<int> mySet;
    cin >> N >> K;
    
    queue < pair<int, int> > q;
    q.push(make_pair(N, 0));
    mySet.insert(N);
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.first == K) {
            result = s.second;
            break;
        }
        q.pop();
        
        if (mySet.find(s.first - 1) == mySet.end() && s.first - 1 >= 0) {
            q.push(make_pair(s.first - 1, s.second + 1));
            mySet.insert(s.first - 1);
        }
        
        if (mySet.find(s.first + 1) == mySet.end() && s.first + 1 <= 100000) {
            q.push(make_pair(s.first + 1, s.second + 1));
            mySet.insert(s.first + 1);
        }
        
        if (mySet.find(s.first * 2) == mySet.end() && s.first * 2 <= 100000) {
            q.push(make_pair(s.first * 2, s.second + 1));
            mySet.insert(s.first * 2);
        }
    }
    
    cout << result;
    return 0;
}
