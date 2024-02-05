
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<int> v (N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int result = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K / v[i] == 0) {
            continue;
        }
        
        result = result + K / v[i];
        K = K % v[i];
        
    }
    
    cout << result;
    return 0;
}
