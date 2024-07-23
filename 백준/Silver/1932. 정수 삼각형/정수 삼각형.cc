#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v;
    int data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> data;
            v.push_back(data);    
        }
    }
    
    
    if (N == 1) {
        cout << v[0];
    } else if (N == 2) {
        int result = v[0] + v[1] > v[0] + v[2] ? v[0] + v[1] : v[0] + v[2]; 
        cout << result;
    } else {
        map<int, pair<int, int>> myMap;
        int start = 3;
        for (int i = 3; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                if (j == 1) {
                    myMap[start] = make_pair(i, 1);
                } else if (j == i) {
                    myMap[start] = make_pair(i, 3);
                } else {
                    myMap[start] = make_pair(i, 2);
                }
                start++;
            }
        }
        
        int dp[start];
        dp[0] = v[0];
        dp[1] = v[0] + v[1];
        dp[2] = v[0] + v[2];
        
        for (int i = 3; i < start; i++) {
            pair<int, int> p = myMap[i];
            
            if (p.second == 1) {
                dp[i] = dp[i - (p.first - 1)] + v[i];
            } else if (p.second == 2) {
                dp[i] = max(dp[i - p.first], dp[i - (p.first - 1)]) + v[i];
            } else if (p.second == 3) {
                dp[i] = dp[i - p.first] + v[i];
            }
        }
        
        int ma = -1;
        for (int i = start - 1; i >= start - N; i--) {
            if (ma < dp[i]) {
                ma = dp[i];
            }
        }
        
        cout << ma;
    }
    
    

    return 0;
}