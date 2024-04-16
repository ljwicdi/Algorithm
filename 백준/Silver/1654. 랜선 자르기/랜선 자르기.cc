#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, K;
    cin >> K >> N;
    
    vector<long long> v;
    long long cm, ma = -1;
    for (int i = 0; i < K; i++) {
        cin >> cm;
        v.push_back(cm);
        if (cm > ma) {
            ma = cm;
        }
    }
    
    long long right = ma; 
    long long left = 1;
    long long result;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        
        for (auto s : v) {
            cnt += s / mid;
        }
        
        if (cnt >= N) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << result;
    return 0;
}
