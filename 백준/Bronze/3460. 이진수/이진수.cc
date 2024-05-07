
#include <iostream>
#include <vector>
using namespace std;

vector<int> sol(int n) {
    vector<int> result;
    int index = 0;
    while (n / 2 != 0) {
        if (n % 2 == 1) {
            result.push_back(index);
        }
        n = n / 2;
        index++;
    } 
    
    if (n % 2 == 1) result.push_back(index);
    return result;
}

int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int n;
        cin >> n;
        
        vector<int> result = sol(n);
        
        for (auto s : result) {
            cout << s << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}
