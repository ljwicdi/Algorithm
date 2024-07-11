
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> dp;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    dp.push_back(v[0]);
    dp.push_back(v[0] + v[1]);
    dp.push_back(max(v[1] + v[2], v[0] + v[2]));
    
    for (int i =3; i < N; i++) {
        dp.push_back(max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]));
    }
    
    cout << dp[N - 1];

    return 0;
}