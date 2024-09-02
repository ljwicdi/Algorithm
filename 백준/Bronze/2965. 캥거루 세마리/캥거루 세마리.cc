#include <iostream>
using namespace std;
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (C - B > B - A)
        cout << C - B - 1;
    else
        cout << B - A - 1;
}