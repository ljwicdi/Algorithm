
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    vector<int> v;
    int h;
    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        cin >> h;
        
        v.push_back(h);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= L) {
            L = L + 1;  // 길이 증가
        }
        else {
            break;  // 더이상 못 먹음 
        }
    }
    
    cout << L;
    return 0;
}
