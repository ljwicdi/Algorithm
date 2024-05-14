#include <iostream>
using namespace std;
int main() {
    
    int data, sum = 0;
    while (1) {
        cin >> data;
        if (data == -1) {
            break;
        }
        sum += data;
    }
    
    cout << sum;

    return 0;
}
