#include <iostream>
#include <vector>

using namespace std;


int main() {
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int d, n, s, p;
        cin >> d >> n >> s >> p;
        
        int parallTime = d + n * p;
        int noParallTime = n * s;
        
        if (parallTime < noParallTime) {
            cout << "parallelize\n";
        } else if (parallTime > noParallTime) {
            cout << "do not parallelize\n";
        } else {
            cout << "does not matter\n";
        }
    }
    
}