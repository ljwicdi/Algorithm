
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> v(5, 0);
        for (int j = 0; j < 5; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());
        cout << "Case #" << i + 1 << ": " << v[4] << "\n";
    }
    return 0;
}
