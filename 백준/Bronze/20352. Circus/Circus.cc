
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    std::cout << std::setprecision(10);

    long long a;
    cin >> a;
    
    // pi * r * r = a
    long double rr = a / 3.1415926535;
    long double r = sqrt(rr);
    
    long double result = 2 * 3.1415926535 * r;
    cout << result;

    return 0;
}