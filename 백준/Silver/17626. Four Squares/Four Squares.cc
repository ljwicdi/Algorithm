#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(1);
    // dp[i] = i 보다 작은 제곱수인 j에 관한 dp[j] 중 최소값 
    set<int> mySet;
    for (int i = 1; i < 250; i++) {
        mySet.insert(i * i);
    }
    
    if (mySet.find(n) != mySet.end()) {
            cout << "1";
            exit(0);
    }
    
    for (int i = 2; i <= n; i++) {
        
        if (mySet.find(i) != mySet.end()) {
            dp.push_back(1);
            continue;
        }
        
        int mi = 10000000;
        for (int j = 1; j * j <= i; j++) {
            if (mi > dp[i - j * j]) {
                mi = dp[i - j * j];
            }
        }
        dp.push_back(mi + 1);
    }
    
    
    cout << dp[n];
    return 0;
}
