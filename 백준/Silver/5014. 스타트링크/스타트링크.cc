
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    
    int F, S, G, U, D;
    set<int> mySet;
    
    cin >> F >> S >> G >> U >> D;
    
    queue< pair<int, int> > q;
    q.push(make_pair(S, 0));
    mySet.insert(S);
    int result = 2000000000;
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        if (s.first == G) {
            if (s.second < result) {
                result = s.second;
            }
           
        }
        
        // +U층 
        if (s.first + U <= F) {
            if (mySet.find(s.first + U) == mySet.end()) {
                q.push(make_pair(s.first + U, s.second + 1));
                mySet.insert(s.first + U);
            }
        }
        
        // -D층
        if (s.first - D > 0) {
            if (mySet.find(s.first - D) == mySet.end()) {
                q.push(make_pair(s.first - D, s.second + 1));
                mySet.insert(s.first - D);
            }   
        }
    }
    
    if (result == 2000000000) {
        cout << "use the stairs";
    } else {
        cout << result;
    }
    
    return 0;
}
