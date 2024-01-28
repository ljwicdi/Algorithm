
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<string, vector<string>> myMap;
    int N;
    
    cin >> N;
    
    string parent, child;
    for (int i = 0; i < N - 1; i++) {
        cin >> child >> parent;
        
        if (myMap.find(parent) == myMap.end()) {
            vector<string> v;
            v.push_back(child);
            myMap[parent] = v;
        } else {
            myMap[parent].push_back(child);
        }
    }
    
    string class1, class2;
    cin >> class1 >> class2;
    
    queue<string> q;
    q.push(class1);
    set<string> mySet;
    mySet.insert(class1);
    
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s == class2) {
            result = 1;
            break;
        }
        q.pop();
        for (auto k : myMap[s]) {
            if (mySet.find(k) == mySet.end()) {
                mySet.insert(k);
                q.push(k);
            }
        }
    }
    
    if (result == 1) {
        cout << "1\n";
        return 0;
    }
    
    queue<string> q2;
    q2.push(class2);
    set<string> mySet2;
    mySet2.insert(class2);
    
    
    while (!q2.empty()) {
        auto s = q2.front();
        
        if (s == class1) {
            result = 1;
            break;
        }
        q2.pop();
        for (auto k : myMap[s]) {
            if (mySet2.find(k) == mySet2.end()) {
                mySet2.insert(k);
                q2.push(k);
            }
        }
    }
    
    if (result == 1) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}
