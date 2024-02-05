
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp {
    
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second) {
            return true;
        } else if (a.second == b.second) {
            if (a.first > b.first) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

int main()
{
    // 디폴트 -> 최대힙, second 값이 가장 작은 것부터 우선순위를 가지게 만든다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int N;
    cin >> N;
    
    int start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        pq.push(make_pair(start, end));
    }
    
    int result = 0;
    int back = 0;
    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        if (back <= temp.first) {
            result++;
            back = temp.second;
            
        }
        pq.pop();
        
    }
    
    cout << result;
    
    
    
    return 0;
}
