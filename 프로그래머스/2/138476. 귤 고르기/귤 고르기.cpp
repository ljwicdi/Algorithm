#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> myMap;
    
    for (int i = 0; i < tangerine.size(); i++) {
        if (myMap.find(tangerine[i]) == myMap.end()) {
            myMap[tangerine[i]] = 1;
        } else {
            myMap[tangerine[i]]++;
        }
    }
    
    vector<pair<int, int>> v(myMap.begin(), myMap.end());
    sort(v.begin(), v.end(), comp);
    for (auto s : v) {
        if (k > 0) {
            k = k - s.second;
            answer++;
        } else {
            break;
        }
    }
    return answer;
}