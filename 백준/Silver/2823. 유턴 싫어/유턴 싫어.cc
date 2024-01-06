
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int R, C;
    char data;
    cin >> R >> C;
    vector<char> v[R];
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    int chk = 0;
    int xCount = 0;
    for (int i = 0; i < R; i++) {
        for (int j =0; j < R; j++) {
            if (v[i][j] == '.') {
                if (i == 0 && j == 0) {
                    if (v[i + 1][0] == 'X' || v[0][j + 1] == 'X') {
                        chk = 1;
                    }
                } else if (i == 0 && j > 0 && j < C - 1) {
                    if (v[0][j - 1] == 'X') {
                        xCount++;
                    }
                    if (v[0][j + 1] == 'X') {
                        xCount++;
                    }
                    if (v[1][j] == 'X') {
                        xCount++;
                    }
                    
                    if (xCount >= 2) {
                        chk = 1;
                    }
                    xCount = 0;
                } else if (i == 0 && j == C - 1) {
                    if (v[0][j - 1] == 'X' || v[1][j] == 'X') {
                        chk = 1;
                    }
                } else if (i > 0 && i < R - 1 && j == 0) {
                    if (v[i - 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i + 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i][j + 1] == 'X') {
                        xCount++;
                    }
                    
                    if (xCount >= 2) {
                        chk = 1;
                    }
                    
                    xCount = 0;
                } else if (i > 0 && j > 0 && j < C - 1 && i < R - 1) {
                    if (v[i][j + 1] == 'X') {
                        xCount++;
                    }
                    if (v[i - 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i][j - 1] == 'X') {
                        xCount++;
                    }
                    if (v[i + 1][j] == 'X') {
                        xCount++;
                    }
                    if (xCount >= 3) {
                        chk = 1;
                    }
                    xCount = 0;
                } else if (i > 0 && i < R - 1 && j == C - 1) {
                    if (v[i - 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i][j - 1] == 'X') {
                        xCount++;
                    }
                    if (v[i + 1][j] == 'X') {
                        xCount++;
                    }
                    if (xCount >= 2) {
                        chk = 1;
                    }
                    xCount = 0;
                } else if (i == R - 1 && j == 0) {
                    if (v[i - 1][0] == 'X') {
                        xCount++;
                    }
                    if (v[i][j + 1] == 'X') {
                        xCount++;
                    }
                    if (xCount >= 1) {
                        chk = 1;
                    }
                    xCount = 0;
                } else if (i == R - 1 && j > 0 && j < C - 1) {
                    if (v[i][j - 1] == 'X') {
                        xCount++;
                    }
                    if (v[i - 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i][j + 1] == 'X') {
                        xCount++;
                    }
                    if (xCount >= 2) {
                        chk = 1;
                    }
                    xCount = 0;
                } else if (i == R - 1 && j == C - 1) {
                    if (v[i - 1][j] == 'X') {
                        xCount++;
                    }
                    if (v[i][j - 1] == 'X') {
                        xCount++;
                    }
                    if (xCount >= 1) {
                        chk = 1;
                    }
                    xCount = 0;
                }
            }
        }
    }
    if (chk == 1) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}
