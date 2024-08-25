#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ids[51];

int find(int node) {
   
    while (node != ids[node]) {
        node = ids[node];
    }
   
    return node;
}

void uni(int a, int b) {
   
    if (find(a) == find(b)) return;
   
    int node1 = find(a);
    int node2 = find(b);
   
    if (node1 < node2) {
        ids[node2] = node1;
    } else {
        ids[node1] = node2;
    }
}

int main() {
   
    int N, M, cnt;
    cin >> N >> M;
    cin >> cnt;
   
    for (int i = 0; i < 51; i++) {
        ids[i] = i;
    }
   
    vector<int> truth(cnt);
    for (int i = 0; i < cnt; i++) {
        cin >> truth[i];
    }
   
    vector<vector<int>> party(M);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
       
        for (int j = 0; j < num; j++) {
            int data;
            cin >> data;
            party[i].push_back(data);
        }
    }
   
    if (cnt == 0) {
        cout << M;
        return 0;
    }
   
   
   
    for (int i = 0; i < M; i++) {
        vector<int> partyMembers = party[i];
       
        for (int j = 0; j < partyMembers.size() - 1; j++) {
            int a = partyMembers[j];
            int b = partyMembers[j + 1];
           
            uni(a, b);
        }
    }
   
    set<int> root;
    for (int i = 0; i < truth.size(); i++) {
        root.insert(find(truth[i]));
    }
   
    int result = M;
    for (int i = 0; i < M; i++) {
        vector<int> partyMembers = party[i];
        for (int j = 0; j < partyMembers.size(); j++) {
           
            if (root.find(find(partyMembers[j])) != root.end()) {
                result--;
                break;
            }
        }
       
    }
   
    cout << result;
    return 0;
}