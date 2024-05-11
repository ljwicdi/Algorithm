
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    vector<int> a(10);
    vector<int> b(10);
    
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    cout << a[9] + a[8] + a[7] << " ";
    cout << b[9] + b[8] + b[7];
    return 0;
}
