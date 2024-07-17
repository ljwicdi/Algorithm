
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    vector<long long> v(n + 1);
    v[1] = 1;
    v[2] = 3;
    if (n == 1) {
        cout << "1";
        return 0;
    } else if (n == 2) {
        cout << "3";
        return 0;
    }
    
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i - 1] + 2 * v[i - 2]) % 10007;
    }
    
    cout << v[n];
    
    return 0;
}