#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> v(N);
    int upDp[N];
    int downDp[N];
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        upDp[i] = 1;
        downDp[i] = 1;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                upDp[i] = max(upDp[i], upDp[j] + 1);
            }
        }
    }
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (v[j] < v[i]) {
                downDp[i] = max(downDp[i], downDp[j] + 1);
            }
        }
    }
    
    int result = upDp[0] + downDp[0];
    for (int i = 1; i < N; i++) {
        if (result < upDp[i] + downDp[i]) {
            result = upDp[i] + downDp[i];
        }
    }

    cout << result - 1;
    return 0;
}