
#include <iostream>
using namespace std;
int main() {
    
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    
    int sero, garo;
    if (W % (M + 1) == 0 ) {
        sero = W / (M + 1);    
    } else {
        sero = W / (M + 1) + 1;
    }
    
    if (H % (N + 1) == 0) {
        garo = H / (N + 1);
    } else {
        garo = H / (N + 1) + 1;
    }
    
    cout << sero * garo;
    return 0;
}
