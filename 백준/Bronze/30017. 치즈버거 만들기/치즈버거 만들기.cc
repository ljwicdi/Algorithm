
#include <iostream>
using namespace std;
int main()
{
    int A, B;
    cin >> A >> B;
    int result = 3;
    A = A - 2;
    B = B - 1;
    while (A > 0 && B > 0) {
        A--;
        B--;
        result+=2;
    }

    
    cout << result;
    return 0;
}
