#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    
    int jump = N - 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < jump; j++) {
            cout << " ";
        }
        
        for (int j = 0; j < i; j++) {
            if (j == i - 1) {
                cout << "*";
                break;
            }
            
            cout << "* ";
        }
        
        cout << "\n";
        jump--;
    }
    
    return 0;
}
