
#include <iostream>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    int n;
    for (int i = 0; i < testCase; i++) {
        cin >> n;
        
        cout << "Pairs for " << n << ": ";
        
        int left = 1, right = n - 1;
        while (1) {
            if (left >= right) {
                break;
            }
            
            if (left + 1 >= right - 1) {
                cout << left  << " " << right;
            } else {
                cout << left  << " " << right << ", ";
            }
           
            left++;
            right--;
            
        }
        
        cout << "\n";
    }

    return 0;
}
