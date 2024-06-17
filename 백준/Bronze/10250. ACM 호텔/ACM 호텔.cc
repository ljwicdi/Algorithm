
#include <iostream>
using namespace std;
int main() {
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int H, W, N;
        cin >> H >> W >> N;
        
        int height;
        if (N % H == 0) {
            height = H;
        } else {
            height = N % H;
        }
        
        int width;
        if (N % H == 0) {
            width = N / H;
        } else {
            width = N / H + 1;
        }
        
        string result;
        if (width <= 9 && width >= 1) {
            result = to_string(height) + "0" + to_string(width);
        } else {
            result = to_string(height) + to_string(width);
        }
        
        cout << result << "\n";
        
    }

    return 0;
}