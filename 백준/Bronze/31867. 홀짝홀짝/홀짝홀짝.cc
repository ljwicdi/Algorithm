
#include <iostream>
using namespace std;
int main() {
    
    int N, oddCnt = 0, evenCnt = 0;
    cin >> N;
    char data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        if ((data - '0') % 2 == 0) {
            evenCnt++;
        } else {
            oddCnt++;
        }
    }
    

    if (evenCnt > oddCnt) {
        cout << "0";
    } else if (evenCnt < oddCnt) {
        cout << "1";
    } else {
        cout << "-1";
    }

    return 0;
}