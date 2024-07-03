#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, X;
    vector<int> v;
    cin >> N >> X;
    
    int data;
    for (int i = 0; i < N; i++) {
        cin >> data;
        v.push_back(data);
    }
    

    int cnt = v[0] + v[1];
    int left = 1, right = 2;
    while (right < N) {
        if (cnt > v[left] + v[right]) {
            cnt = v[left] + v[right];
        }
        
        left++;
        right++;
    }
    
    long long result = X * cnt;
    cout << result;

    return 0;
}