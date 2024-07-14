
#include <iostream>
using namespace std;
int main() {
    int H1, B1, H2, B2;
    cin >> H1 >> B1;
    cin >> H2 >> B2;
    
    int player1 = H1 * 3 + B1 * 1;
    int player2 = H2 * 3 + B2 * 1;
    
    if (player1 > player2) {
        cout << "1 " << player1 - player2;
    } else if (player1 < player2) {
        cout << "2 " << player2 - player1;
    } else {
        cout << "NO SCORE";
    }

    return 0;
}