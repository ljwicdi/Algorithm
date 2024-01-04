#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, K, data;
    string originalStr;
    vector<int> v;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> data;
        originalStr = originalStr + to_string(data);
        v.push_back(data);
    }
    
    sort(v.begin(), v.end());
    
    string sortStr;
    
    for (auto s : v) {
        sortStr = sortStr + to_string(s);
    }
    
    // 정렬된 값 -> 항상 이 string과 비교해서 체크
    
    queue< pair<string, int> > q;
    q.push(make_pair(originalStr, 0));
    int result = -1;
    set<string> mySet;
    mySet.insert(originalStr);
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        if (s.first == sortStr) {
            result = s.second;
            break;
        }
        
        string temp = s.first;
        for (int i = 0; i <= s.first.length() - K; i++) {
            string reverse;
            string newStr;
            
            for (int k = 0; k < i; k++) {
                newStr = newStr + temp[k];
            }
            for (int j = i + K - 1; j >= i; j--) {
                reverse = reverse + temp[j];
            }
            newStr = newStr + reverse;
            
            for (int k = i + K; k < s.first.length(); k++) {
                newStr = newStr + temp[k];
            }
            
            if (mySet.find(newStr) == mySet.end()) {
                q.push(make_pair(newStr, s.second + 1));
                mySet.insert(newStr);
            }
        }
        
        
    }
    
    cout << result;
    return 0;
}
