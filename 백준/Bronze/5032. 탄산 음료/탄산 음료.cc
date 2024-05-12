
#include <iostream>
using namespace std;
int main() {
    
    int e, f, c;
    cin >> e >> f >> c;
    
    int bottle = e + f;
    int result = 0;
    while (bottle - c >= 0) {
        result++;
        bottle = bottle - c;
        bottle++;
    }
    
    cout << result;
    return 0;
}
