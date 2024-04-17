#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main() {
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    
    
    int L;
    cin >> L;
    string str;
    cin >> str;
    
    long long sum = 0;
    for (int i = 0; i < L; i++) {
        sum = sum + (str[i] - 96) * pow(31, i);
    }
    cout << sum % 1234567891;
    return 0;
}
