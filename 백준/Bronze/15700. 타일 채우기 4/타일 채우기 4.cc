
#include <iostream>
using namespace std;
int main()
{
    long long N, M;
    cin >> N >> M;
    
    long long result = 0;
    if (N == 1 && M == 1) {
        result = 0;
    } else {
        result = result + (N * (M / 2));
        
        if (M % 2 == 1) {
            result = result + (N / 2);
        }
    }
    
    cout << result;
    return 0;
}
