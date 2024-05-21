
#include <iostream>
using namespace std;
int main() {
    
    int n, k;
    
    while (cin >> n >> k) {
        int result = n;
        
        while (n - k >= 0) {
            n = n - k;
            result++;
            n++;
        }
        cout << result << "\n";
    }
    

    return 0;
}
