
#include <iostream>
using namespace std;
int main()
{
    int H, I, A, R, C;
    cin >> H >> I >> A >> R >> C;
    
    int first = H * I;
    int second = A * R * C;
    cout << first - second;

    return 0;
}
