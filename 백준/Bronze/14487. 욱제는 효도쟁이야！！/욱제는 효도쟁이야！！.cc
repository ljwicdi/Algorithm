
#include <iostream>
using namespace std;
int main() {
    
    int n, data, sum = 0, ma = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        sum += data;
        if (ma < data) {
            ma = data;
        }
    }
    
    cout << sum - ma;
    
    return 0;
}
