
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    vector<int> v[n];
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    vector<pair<int, int>> cost;
    int white, black;
    for (int i = 0; i < n; i++) {
        // 흰, 검;
        cin >> white >> black;
        cost.push_back(make_pair(white, black));
    }
    
    // 첫번째 경우 .. 흰 검 흰 검 .. .
    // 짝수면 흰색 홀수면 검은색
    long long sum1 = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        auto s = q.front();
        if (s.second % 2 == 0) {
            sum1 = sum1 + cost[s.first].first;
        } else {
            sum1 = sum1 + cost[s.first].second;
        }
        q.pop();
        
        for (auto k : v[s.first]) {
            q.push(make_pair(k, s.second + 1));
        }
    }
    
    // 두번째 경우 .. 검 흰 검 흰 ... 
    long long sum2 = 0;
    queue<pair<int, int>> q2;
    q2.push(make_pair(0, 0));
    
    while (!q2.empty()) {
        auto s = q2.front();
        if (s.second % 2 == 0) {
            sum2 = sum2 + cost[s.first].second;
        } else {
            sum2 = sum2 + cost[s.first].first;
        }
        q2.pop();
        
        for (auto k : v[s.first]) {
            q2.push(make_pair(k, s.second + 1));
        }
    }
    
    if (sum1 < sum2) {
        cout << sum1;
    } else {
        cout << sum2;
    }
    return 0;
}
