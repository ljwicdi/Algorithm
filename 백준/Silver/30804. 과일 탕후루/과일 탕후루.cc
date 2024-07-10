#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    
    if (N <= 2) {
        cout << N;
        return 0;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    unordered_map<int, int> count;
    int left = 0, right = 0, ma = 2;
    
    while (right < N) {
        count[v[right]]++;
        
        while (count.size() > 2) {
            count[v[left]]--;
            if (count[v[left]] == 0) {
                count.erase(v[left]);
            }
            left++;
        }
        
        ma = max(ma, right - left + 1);
        right++;
    }
    
    cout << ma;
    
    return 0;
}
