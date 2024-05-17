
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int currentMax = v[0];
    int left = 1;
    
    for (int i = 1; i < N; i++) {
        if (currentMax < v[i]) {
            left++;
            currentMax = v[i];
        }
    }
    
    currentMax = v[N - 1];
    int right = 1;
    
    for (int i = N - 2; i >= 0; i--) {
        if (currentMax < v[i]) {
            right++;
            currentMax = v[i];
        }
    }
    
    cout << left << "\n" << right;

    return 0;
}
