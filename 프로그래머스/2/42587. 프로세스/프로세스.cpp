#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    map<int, int> myMap;
    for (int i = 0; i < priorities.size(); i++) {
        if (myMap.find(priorities[i]) == myMap.end()) {
            myMap[priorities[i]] = 1;
        } else {
            myMap[priorities[i]]++;
        }
        q.push(make_pair(i, priorities[i]));
    }
    
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        
        myMap[s.second]--;
        bool flag = false;
        for (auto k : myMap) {
            if (k.first > s.second) {
                // 더 큰 원소가 존재하면 프로세스 실행을 못함 
                // 큐 마지막에 가야함 
                if (k.second > 0) {
                    flag = true;
                    myMap[s.second]++;
                    q.push(s);
                    break;
                }
            }
        }
        // 더 큰 것이 없다면 프로세스 실행
        if (flag == false && s.first == location) {
            answer = answer + 1;
            break;
        }
        if (flag == false)
            answer++;
    }
    return answer;
}