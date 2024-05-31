
#include <iostream>
#include <vector>
using namespace std;

pair<string, int> sol(string problem, string pattern) {
    
    int patternLength = pattern.length();
    int startIndex = 0;
    int cnt = 0;
    
    while (1) {
        
        int patternIndex = 0;
        for (int i = startIndex; i < startIndex + patternLength; i++) {
            if (i >= problem.length()) {
                break;
            }
        
            if (problem[i] == pattern[patternIndex++]) {
                cnt++;
            }
            
            if (patternIndex >= patternLength) {
                break;
            }
            
            
        }
        
        startIndex += patternLength;
        
        if (startIndex >= problem.length()) {
            break;
        }
        
        
    }
    
    if (pattern == "ABC") {
        return make_pair("Adrian", cnt);
    } else if (pattern == "BABC") {
        return make_pair("Bruno", cnt);
    } else  {
        return make_pair("Goran", cnt);
    }
    
}

int main() {
    
    int N;
    cin >> N;
    string str;
    cin >> str;
    
    vector<pair<string, int>> v;
    pair<string, int> result;
    v.push_back(sol(str, "ABC"));
    v.push_back(sol(str, "BABC"));
    v.push_back(sol(str, "CCAABB"));
    
    int ma = v[0].second;
    
    for (int i = 1; i < 3; i++) {
        if (ma < v[i].second) {
            ma = v[i].second;
        }
    }
    
    
    cout << ma << "\n";
    for (int i = 0; i < 3; i++) {
        if (ma == v[i].second) {
            cout << v[i].first << "\n";
        }
    }
    return 0;
}
