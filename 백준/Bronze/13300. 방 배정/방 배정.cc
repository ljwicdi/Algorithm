
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    int N, K;
    cin >> N >> K;
    
    int gender, grade;
    vector<pair<int, int>> v(6, make_pair(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> gender >> grade;
        
        if (gender == 0) {
            v[grade - 1].first = v[grade - 1].first + 1; 
        } else {
            v[grade - 1].second = v[grade - 1].second + 1;   
        }
    }
    
    int result = 0;
    
    for (auto s : v) {
        if (s.first % K == 0) {
            result = result + (s.first / K);
        } else {
            result = result + (s.first / K + 1);
        }
        
        if (s.second % K == 0) {
            result = result + (s.second / K);
        } else {
            result = result + (s.second / K + 1);
        }
    }
    
    cout << result;
    
    return 0;
}
