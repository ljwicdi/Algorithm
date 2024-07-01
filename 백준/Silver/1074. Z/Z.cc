#include <iostream>
using namespace std;
long long cnt = 0;
long long result, r, c;
void solve(long long startX, long long endX, long long startY, long long endY) {
    if (endX - startX == 1) {
        if (r == startX && c == startY) {
            cout << cnt;
            exit(0);   
        }
        return;
    }
    
    if (startX <= r && r < (startX + endX) / 2 && startY <= c && c < (startY + endY) / 2) {
        solve(startX, (startX + endX) / 2, startY, (startY + endY) / 2);
    }
    cnt = cnt + ((endX - startX) / 2) * ((endX - startX) / 2);
    
    if (startX <= r && r < (startX + endX) / 2 && (startY + endY) / 2 <= c && c < endY) {
        solve(startX, (startX + endX) / 2, (startY + endY) / 2, endY);    
    }
    
    cnt = cnt + ((endX - startX) / 2) * ((endX - startX) / 2);
    if ((startX + endX) / 2 <= r && r < endX && startY <= c && c < (startY + endY) / 2) {
        solve((startX + endX) / 2, endX, startY, (startY + endY) / 2);    
    }
    
    cnt = cnt + ((endX - startX) / 2) * ((endX - startX) / 2);
    if ((startX + endX) / 2 <= r && r < endX && (startY + endY) / 2 <= c && c < endY) {
        solve((startX + endX) / 2, endX, (startY + endY) / 2, endY);    
    }
    
}

int main() {
    long long N;
    cin >> N >> r >> c;
    long long length = 1;
    for (long long i = 1; i <= N; i++) {
        length *= 2;
    }
    
    if (0 <= r && r < length / 2 && 0 <= c && c < length / 2) {
        solve(0, length / 2, 0, length / 2);   
    }
    cnt = cnt + (length / 2) * (length / 2);
    
    if (0 <= r && r < length / 2 && length / 2 <= c && c < length) {
        solve(0, length / 2, length / 2, length);    
    }
    cnt = cnt + (length / 2) * (length / 2);
    
    if (length / 2 <= r && r < length && 0 <= c && c < length / 2) {
        solve(length / 2, length, 0, length / 2);   
    }
    cnt = cnt + (length / 2) * (length / 2);
    
    if (length / 2 <= r && r < length && length / 2 <= c && c < length) {
        solve(length / 2, length, length / 2, length);    
    }
    
    return 0;
}