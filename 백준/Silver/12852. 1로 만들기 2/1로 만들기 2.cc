
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N;
    set<int> mySet;
    cin >> N;
    
    queue< vector<int> > q;
    
    q.push( vector<int> {N});
    mySet.insert(N);
    int result = 0;
    vector<int> v;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s[s.size() - 1] == 1) {
            result = s.size() - 1;
            for (int i = 0; i < s.size(); i++) {
                v.push_back(s[i]);
            }
            break;
        }
        
        q.pop();
        
        int chk = 0;
        if (s[s.size() - 1] % 3 == 0 && mySet.find(s[s.size() - 1] / 3) == mySet.end()) {
            s.push_back(s[s.size() - 1] / 3);
            q.push(s);
            mySet.insert(s[s.size() - 1]);
            chk = 1;
        }
        
        if (s[s.size() - 1] % 2 == 0 && mySet.find(s[s.size() - 1] / 2) == mySet.end()) {
            if (chk == 0) {
                s.push_back(s[s.size() - 1] / 2);
                q.push(s);
                mySet.insert(s[s.size() - 1]);
                chk = 1;
            } else if (chk == 1) {
                s[s.size() - 1] = s[s.size() - 2] / 2;
                q.push(s);
                mySet.insert(s[s.size() - 1]);
            }
        }
        
        if (mySet.find(s[s.size() - 1] - 1) == mySet.end()) {
            if (chk == 0) {
                s.push_back(s[s.size() - 1] - 1);
                q.push(s);
                mySet.insert(s[s.size() - 1]);
            } else if (chk == 1) {
                s[s.size() - 1] = s[s.size() - 2] - 1;
                q.push(s);
                mySet.insert(s[s.size() - 1]);
            }
            
        }
        
    }
    
    cout << result << "\n";
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}
