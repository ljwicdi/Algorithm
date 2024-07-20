
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    vector<int> dp(N, 1);
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                
            }
        }
    }
    
    int ma = -1;
    
    for (int i = 0; i < N; i++) {
        if (ma < dp[i]) {
            ma = dp[i];
        }
    }
    
    cout << ma;
    return 0;
}