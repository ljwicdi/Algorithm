#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    // '{', '}' 없애기
    string newStr = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '{' && s[i] != '}') {
            newStr += s[i];
        }
    }
    istringstream ss (newStr);
    vector<string> sub;
    string temp;
    while (getline(ss, temp, ',')) {
        sub.push_back(temp);
    }
    map<string, int> myMap;
    for (int i = 0; i < sub.size(); i++) {
        if (myMap.find(sub[i]) != myMap.end()) {
            myMap[sub[i]]++;
        } else {
            myMap[sub[i]] = 1;
        }
    }
    
    vector<pair<string, int>> t(myMap.begin(), myMap.end());
    sort(t.begin(), t.end(), comp);
    
    for (auto s : t) {
        answer.push_back(stoi(s.first));
    }
    return answer;
}