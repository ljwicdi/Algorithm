#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct node {
  int my;
  int yours;
  int distance;
};
int main()
{
    int C;
    cin >> C;
    
    int S, T;
    for (int i = 0; i < C; i++) {
        cin >> S >> T;
        
        queue<node> q;
        node nd;
        nd.my = S;
        nd.yours = T;
        nd.distance = 0;
        q.push(nd);
        
        int result = 0;
        int nextMy, nextYours;
        set<pair<int, int>> mySet;
        mySet.insert(make_pair(S, T));
        while (!q.empty()) {
            auto s = q.front();
            if (s.my == s.yours) {
                result = s.distance;
                break;
            }
            
            
            q.pop();
            
            // A 발차기
            nextMy = s.my + s.my;
            nextYours = s.yours + 3;
            
            if (mySet.find(make_pair(nextMy, nextYours)) == mySet.end()) {
                if (2 * s.my <= s.yours + 3) {
                    mySet.insert(make_pair(nextMy, nextYours));
                    node nd;
                    nd.my = nextMy;
                    nd.yours = nextYours;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                }
                
            }
            
            // B 발차기
            nextMy = s.my + 1;
            nextYours = s.yours;
            
            if (mySet.find(make_pair(nextMy, nextYours)) == mySet.end()) {
                mySet.insert(make_pair(nextMy, nextYours));
                node nd;
                nd.my = nextMy;
                nd.yours = nextYours;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        cout << result << "\n";
    }
    return 0;
}
