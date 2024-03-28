
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int leafNodeCnt;

void dfs(int node, vector<set<int>> & v) {
    
    if (v[node].size() == 0) {
        leafNodeCnt++;
        return;
    }
    
    for (auto s : v[node]) {
        dfs(s, v);
    }
}
int main() {
    leafNodeCnt = 0;
    int N;
    cin >> N;
    vector<set<int>> v(N);
    vector<int> parent;
    
    int parentNode;
    int rootNode;
    for (int i = 0; i < N; i++) {
        cin >> parentNode;
        parent.push_back(parentNode);
        
        if (parentNode == -1) {
            rootNode = i;
            
        } else {
            v[parentNode].insert(i);
        }
        
       
    }
    
    int deleteNode;
    cin >> deleteNode;
    
    int deleteNodeParent = parent[deleteNode];
    // deleteNodeParent == -1 이라면 루트노드를 삭제하는 것임..
    if (deleteNodeParent == -1) {
        cout << "0";
        exit(0);
    }
    v[deleteNodeParent].erase(deleteNode);
    
    dfs(rootNode, v);
    
    cout << leafNodeCnt;
    return 0;
}
