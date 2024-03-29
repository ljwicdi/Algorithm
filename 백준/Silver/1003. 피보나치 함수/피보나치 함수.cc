
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    int zero[41];
    int one[41];
    zero[0] = 1; zero[1] = 0;
    one[0] = 0; one[1] = 1;
    for (int i = 2; i < 41; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
    
    int N;
    for (int i = 0; i < testCase; i++) {
        cin >> N;
        cout << zero[N] << " " << one[N] << "\n";
    }
    return 0;
}
