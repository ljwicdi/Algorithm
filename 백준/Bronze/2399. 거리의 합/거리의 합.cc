
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] > v[j]) {
                sum = sum + (v[i] - v[j]);
            } else {
                sum = sum + (v[j] - v[i]);
            }
        }
    }
    
    cout << sum;
    return 0;
}
