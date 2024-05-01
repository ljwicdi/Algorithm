
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    
    if (n == 1) {
        cout << "1";
    } else {
        for (int i = 2; i <= n; i++) {
            v.push_back(v[i - 1] + v[i - 2]);
        }
        
        cout << v[n];
    }
    return 0;
}
