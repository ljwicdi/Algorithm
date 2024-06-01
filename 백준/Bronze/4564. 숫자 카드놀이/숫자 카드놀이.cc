
#include <iostream>
using namespace std;
int main() {
    
    int num;
    while (1) {
        cin >> num;
        if (num == 0) break;
        
        if (num >= 1 && num <= 9) {
            cout << num << "\n";
            continue;
            
        }
        cout << num << " ";
        while (1) {
            
            int mul = 1;
            while (num != 0) {
                mul = mul * (num % 10);
                num = num / 10;
            }
        
            cout << mul << " ";
            
            if (mul >= 0 && mul <= 9) {
                break;
            }
            
            num = mul;
        }
        
        cout << "\n";
    }   

    return 0;
}
