
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, data;
    int max = -1;
    int result;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        
        vector<int> v;
        for (int j = 0; j < 5; j++) {
            cin >> data;
            v.push_back(data);
        }
        
        int localMax = -1;
        int sum;
        for (int j = 0; j < v.size() - 2; j++) {
            for (int k = j + 1; k < v.size() - 1; k++) {
                for (int l = k + 1; l < v.size(); l++) {
                    sum = v[j] + v[k] + v[l];
                    if (sum % 10 > localMax) {
                        localMax = sum % 10;
                    }
                }
            }
        }
        
        if (localMax >= max) {
            result = i + 1;
            max = localMax;
        }
    }
    
    cout << result;
    return 0;
}
