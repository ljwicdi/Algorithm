#include<vector>
#include <iostream>
using namespace std;

int main() {
    
    vector<int> v[13];
    
    int a, b;
    for (int i = 0; i < 12; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    // 1. 연결된 노드가 3개임
    vector<int> first;
    for (int i = 1; i <= 12; i++) {
        if (v[i].size() == 3) {
            first.push_back(i);
        }
    }
    
    // 2. 인접 노드에 인접 노드의 개수가 1인 노드가 존재
    vector<int> second;
    for (int targetNode : first) {
        int chk = 0;
        for (int adjoinNode : v[targetNode]) {
            if (v[adjoinNode].size() == 1) {
                chk = 1;
            }
        }
        if (chk == 1) {
            second.push_back(targetNode);
        }
    }
    
    int result;
    for (int targetNode : second) {
        for (int adjoinNode : v[targetNode]) {
            if (v[adjoinNode].size() == 2) {
                result = targetNode;
            }
        }
    }
    cout << result;
    return 0;
}