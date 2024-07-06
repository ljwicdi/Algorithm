
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        sum += data;
    }
    
    sum += (N - 1) * 8;
    
    cout << sum / 24 << " " << sum % 24;
    return 0;
}