#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int N, cluster;
    cin >> N;
    
    vector<int> fileSize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> fileSize[i];
    }
    
    cin >> cluster;
    
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (fileSize[i] % cluster == 0) {
            sum = sum + (cluster * (fileSize[i] / cluster));
        } else {
            sum = sum + (cluster * ((fileSize[i] / cluster) + 1));
        }
    }
    
    cout << sum;

    return 0;
}
