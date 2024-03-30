#include <string>
#include <vector>
#include <map>
using namespace std;

bool check(vector<string> & want, map<string, int> & myMap, vector<int> & number) {
    bool eq = true;
    for (int i = 0; i < want.size(); i++) {
        if (myMap.find(want[i]) == myMap.end()) {
            eq = false;
            break;
        } else {
            if (myMap[want[i]] != number[i]) {
                eq = false;
                break;
            }
        }
    }
    return eq;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // O(n) 풀이가 가능할듯, map 이용
    map<string, int> myMap;
    for (int i = 0; i < 10; i++) {
        if (myMap.find(discount[i]) == myMap.end()) {
            myMap[discount[i]] = 1;
        } else {
            myMap[discount[i]]++;
        }
    }
    
    if (check(want, myMap, number)) answer++;
    int left = 0;
    for (int i = 10; i < discount.size(); i++) {
        if (myMap[discount[left]] == 0) {
            myMap.erase(discount[left]);
        } else {
            myMap[discount[left]]--;
        }
        left++;
        
        if (myMap.find(discount[i]) == myMap.end()) {
            myMap[discount[i]] = 1;
        } else {
            myMap[discount[i]]++;
        }
        
        if (check(want, myMap, number)) answer++;
    }
    return answer;
}