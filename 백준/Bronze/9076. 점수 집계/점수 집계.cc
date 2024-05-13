
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        
        vector<int> score(5);
        
        for (int j = 0; j < 5; j++) {
            cin >> score[j];
        }
        
        sort(score.begin(), score.end());
    
        if (score[3] - score[1] >= 4) {
            cout << "KIN\n";
        } else {
            cout << score[1] + score[2] + score[3] << "\n";
        }
    }
    
    
    return 0;
}
