
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    cout << v[K - 1];
    
    return 0;
}
