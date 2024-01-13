
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int n;  // 돌의 개수
    int start;  // 처음 위치
    vector<int> v;  // 그 자리에서의 점프 거리
    v.push_back(0);
    cin >> n;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        v.push_back(data);
    }
    cin >> start;
    queue<int> q;
    q.push(start);
    set<int> mySet; // 방문 했던 적이 있었는 지에 대한 검사
    mySet.insert(start);
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        if (s + v[s] <= n && mySet.find(s + v[s]) == mySet.end()) {
            q.push(s + v[s]);
            mySet.insert(s + v[s]);
        }
        
        if (s - v[s] >= 1 && mySet.find(s - v[s]) == mySet.end()) {
            q.push(s - v[s]);
            mySet.insert(s - v[s]);
        }
    }
    
    cout << mySet.size();
    return 0;
}
