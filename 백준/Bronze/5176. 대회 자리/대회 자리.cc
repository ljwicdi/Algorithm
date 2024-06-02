
#include <iostream>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int P, M;
        cin >> P >> M;
        int seat[M + 1] = {0, };
        int result = P; 
        int wish;
        for (int j = 0; j < P; j++) {
            cin >> wish;
            if (seat[wish] == 0) {
                seat[wish] = 1;
                result--;
            }
        }
        
        cout << result << "\n";
    }

    return 0;
}
