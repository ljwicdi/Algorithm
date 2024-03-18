
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
    
    int N;
    cin >> N;
    vector<int> v[N + 1];
     // 큐에 들어갔던 원소를 체크하는 배열 
    bool qChk[N + 1] = {false, };
    int data;
    int indegreeCnt[N + 1] = {0,  };
    
    for (int i = 1; i <= N; i++) {
        cin >> data;
        v[i].push_back(data);
        indegreeCnt[data]++;
    }
    
    // indegree 0인 노드를 넣을 큐 
    queue<int> q;
    
    for (int i = 1; i <= N; i++) {
        // indegree가 0이라면 큐에 넣어줌 
        if (indegreeCnt[i] == 0) {
            qChk[i] = true;
            q.push(i);
        }
        
        
    }
    
   
    while (!q.empty()) {
        auto s = q.front();
        
        q.pop();
        
        for (auto k : v[s]) {
            // indegree 하나 줄이고
            indegreeCnt[k]--;
            if (indegreeCnt[k] == 0) {
                q.push(k);
                qChk[k] = true;
            }
        } 
    }
    
    set<int> result;
    for (int i = 1; i <= N; i++) {
        if (qChk[i] == false) {
            result.insert(i);
        }
    }
    
    cout << result.size() << "\n";
    for (auto s : result) {
        cout << s << "\n";
    }
    return 0;
}
