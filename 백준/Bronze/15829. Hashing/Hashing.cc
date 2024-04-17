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
    
    unsigned long sum = 0;
    for (int i = 0; i < L; i++) {
        unsigned long gob = 1;
        for (int j = 0; j < i; j++) {   
            gob = gob * 31 % 1234567891;
        }
        sum = sum + (str[i] - 96) * gob % 1234567891;
        
    }
    cout << sum % 1234567891;
    return 0;
}
