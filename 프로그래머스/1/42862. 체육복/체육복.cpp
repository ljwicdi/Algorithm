#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
  
    int answer = 0;
    answer = n - lost.size();
    set<int> mySet;
    set<int> commonChk;
    
    for (int i = 0; i < reserve.size(); i++) {
        mySet.insert(reserve[i]);
    }
    
    
    for (int i = 0; i < lost.size(); i++) {
        if (mySet.find(lost[i]) != mySet.end()) {
            commonChk.insert(lost[i]);
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        
        if (mySet.find(lost[i]) != mySet.end()) {
            mySet.erase(lost[i]);
            answer++;
            continue;
        }
        
        if (mySet.find(lost[i] - 1) != mySet.end()) {
            if (commonChk.find(lost[i] - 1) == commonChk.end()) {
                mySet.erase(lost[i] - 1);
                answer++;
                continue;
            }
        }
        
        if (mySet.find(lost[i] + 1) != mySet.end()) {
            if (commonChk.find(lost[i] + 1) == commonChk.end()) {
                mySet.erase(lost[i] + 1);
                answer++;
                continue;
            }
        }
        
        
    }
    
    
    return answer;
}