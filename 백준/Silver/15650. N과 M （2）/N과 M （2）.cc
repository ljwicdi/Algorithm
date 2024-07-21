
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> v;
    vector<int> temp(N, false);
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }
    
    for (int i = 0; i < M; i++) {
        temp[i] = true;
    }
    
    do {
        for (int i = 0; i < N; i++) {
            if (temp[i] == true) {
                cout << v[i] << " ";
            }
        }
        cout << "\n";
    } while (prev_permutation(temp.begin(), temp.end()));
    
    
    return 0;
}