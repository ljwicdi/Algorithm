#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    
    int N, M;
    cin >> N >> M;
    
    vector<int> v[N + 1];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int k;
    cin >> k;
    set<int> mySet;
    int city;
    for (int i = 0; i < k; i++) {
        cin >> city;
        mySet.insert(city);
    }
    
    vector<int> result;
    set<int> bombList;
    for (int i = 1; i <= N; i++) {
        if (mySet.find(i) == mySet.end()) {
            continue;
        }
        bool flag = false;
        vector<int> bomb;
        bomb.push_back(i);
        for (auto s : v[i]) {
            if (mySet.find(s) == mySet.end()) {
                flag = true;
                break;
            }
            bomb.push_back(s);
        }
        
        if (!flag) {
            result.push_back(i);
            for (int j = 0; j < bomb.size(); j++) {
                bombList.insert(bomb[j]);
            }
        }
    }
    
    bool isSame = true;
    for (auto s : bombList) {
        if (mySet.find(s) == mySet.end()) {
            isSame = false;
            break;
        } 
    }
    
    if (bombList.size() != k) {
        isSame = false;
    }
    
    if (result.size() == 0 || isSame == false) {
        cout << "-1";
    } else {
        cout << result.size() << "\n";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
    return 0;
}
