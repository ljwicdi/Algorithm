
#include <iostream>
using namespace std;
int main() {
    int num1, num2;
    cin >> num1 >> num2;
    
    int front, back;
    int a = 100 - num1;
    int b = 100 - num2;
    
    int c = 100 - (a + b);
    int d = a * b;
    front = c;
    back = d;
    
    int q = d / 100;
    int r = d % 100;
    if (d >= 100) {
        front = c + q;
        back = r;
    }
    
    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
    cout << front << " " << back;

    return 0;
}