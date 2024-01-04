#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int N, data;
    vector<int> v;
    set<int> mySet;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> data;
        
        v.push_back(data);
    }
    
    queue< pair<int, int> > q;   // queue에는 pair(인덱스, 점프 수) 저장
    q.push(make_pair(0, 0));  // 현재 위치 index -> 0, 점프 수 -> 0
    mySet.insert(0);
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        // 마지막 인덱스에 도달했다면
        if (s.first == v.size() - 1) {
            result = s.second;
            break;
        }
        
        q.pop();
        
        for (int i = 1; i <= v[s.first]; i++) {
            if (mySet.find(s.first + i) == mySet.end()) {
                if (s.first + i <= v.size() - 1) {
                    q.push(make_pair(s.first + i, s.second + 1));
                    mySet.insert(s.first + i);
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
