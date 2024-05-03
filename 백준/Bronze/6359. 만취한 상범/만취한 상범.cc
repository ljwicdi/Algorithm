
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int testCase;
    cin >> testCase;
    
    int n;

    for (int i = 0; i < testCase; i++) {
        cin >> n;
        vector<int> v(n + 1, 1);
        
        for (int j = 2; j <= n; j++) {
            int index = j;
            
            while (index <= n) {
                if (v[index] == 0) {
                    v[index] = 1;
                } else {
                    v[index] = 0;
                }
                index = index + j;
            }
        }
        
        int result = 0;
        for (auto s : v) {
            if (s == 1) {
                result++;
            }
        }
        
        cout << result - 1 << "\n";
    }
    

    return 0;
}
