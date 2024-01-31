
#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> myMap;
    string a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        
        myMap[a] = c;
    }
    
    int m;
    int chk;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        
        queue<string> q;
        set<string> mySet;
        q.push(a);
        mySet.insert(a);
        chk = 0;
        while (!q.empty()) {
            auto s = q.front();
            if (s == c) {
                chk = 1;
                break;
            }
            q.pop();
            
            if (mySet.find(myMap[s]) == mySet.end()) {
                q.push(myMap[s]);
                mySet.insert(myMap[s]);
            }
            
            
        }
        
        if (chk == 1) {
            cout << "T\n";
        } else {
            cout << "F\n";
        }
    }
    
    
    return 0;
}
