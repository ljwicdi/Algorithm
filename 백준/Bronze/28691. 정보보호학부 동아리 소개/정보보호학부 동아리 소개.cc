
#include <iostream>
using namespace std;
int main() {
    char c;
    cin >> c;
    
    if (c == 'M') {
        cout << "MatKor";
    } else if (c == 'W') {
        cout << "WiCys";
    } else if (c == 'C') {
        cout << "CyKor";
    } else if (c == 'A') {
        cout << "AlKor";
    } else if (c == '$') {
        cout << "$clear";
    }

    return 0;
}