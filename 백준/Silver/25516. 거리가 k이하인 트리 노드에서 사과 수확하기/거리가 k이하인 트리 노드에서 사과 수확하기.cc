
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v[n];
    
    int parent, child;
    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child;
        v[parent].push_back(child);
    }
    
    vector<int> isApple;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        isApple.push_back(data);
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.second > k) {
            q.pop();
            continue;
        }
        
        if (isApple[s.first] == 1) {
            if (s.second <= k) {
                result++;
            }
        }
        q.pop();
        for (int j : v[s.first]) {
            q.push(make_pair(j, s.second + 1));
        }
    }
    
    cout << result;

    return 0;
}
