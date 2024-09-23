#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#define endl '\n'
using namespace std;

//백준 22864번 코드
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a > m) {
        cout << 0 << endl;
        return 0;
    }
    
    int time = 0;
    int sum = 0;
    int result = 0;
    while (time < 24) {
        if (sum + a > m) {
            sum -= c;
            if (sum < 0) { sum = 0; }
        }
        else {
            sum += a;
            result += b;
        }
        time++;
    }
    cout << result << endl;
}