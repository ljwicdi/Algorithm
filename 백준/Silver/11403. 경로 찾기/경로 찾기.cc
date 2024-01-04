
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    int N;
    int data;
    vector<int> v[101];
    vector<int> result[101];
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> data;
            
            if (data == 1) {
                v[i].push_back(j);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        // i번째 노드부터 출발
        bool visited[N] = { false, };
        queue<int> q;
        q.push(i);
        
        while(!q.empty()) {
            int currentNode = q.front();
            q.pop();
            
            for (auto s : v[currentNode]) {
                if (visited[s] == false) {
                    visited[s] = true;
                    q.push(s);
                }
            }
        }
        
        for (int j = 0; j < N; j++) {
            if (visited[j] == true) {
                result[i].push_back(1);
            } else {
                result[i].push_back(0);
            }
        }
        
    }
    
    for (int i = 0; i < N; i++) {
        for (auto s : result[i]) {
            cout << s << " ";
        }
        
        cout << "\n";
    }
           
    return 0;
}
