#include <iostream>
using namespace std;
int main() {
    
    string str1, str2;
    cin >> str1 >> str2;
    
    int lcs[str1.length() + 1][str2.length() + 1];
    
    for (int i = 0; i < str1.length() + 1; i++) {
        for (int j = 0; j < str2.length() + 1; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else if (str1[i - 1] != str2[j - 1]) {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }
    
    int ma = -1;
    for (int i = 0; i < str1.length() + 1; i++) {
        for (int j = 0; j < str2.length() + 1; j++) {
            if (ma < lcs[i][j]) {
                ma = lcs[i][j];
            }
        }
    }
    
    cout << ma;
    
    return 0;
}