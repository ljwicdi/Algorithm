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
    
    int result = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] - v[i - 1] != 1) {
            result += v[i];
        }
    }
    
    cout << result;
    return 0;
}