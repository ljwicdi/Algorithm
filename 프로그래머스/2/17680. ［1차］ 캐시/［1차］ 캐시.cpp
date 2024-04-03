#include <string>
#include <vector>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> deq;
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    int flag = 0;
    
    for (int i = 0; i < cities.size(); i++) {
        string temp = "";
        for (int j = 0; j < cities[i].length(); j++) {
            if (cities[i][j] >= 97 && cities[i][j] <= 122) {
                temp = temp + to_string((cities[i][j] - 32));
            } else {
                temp = temp + to_string(cities[i][j]);
            }
        }
        // 캐시에 해당 도시가 존재한다면
        int index = 0;
        for (string s : deq) {
            if (s == temp) {
                deq.erase(deq.begin() + index);
                deq.push_front(temp);
                answer += 1;
                flag = 1;
                break;
            }
            index++;
        }
        if (flag == 1) {
            flag = 0;
            continue;
        }
        
        // 캐시에 해당 문자열이 존재하지 않는다면 
        // 꽉찼다면
        if (deq.size() == cacheSize) {
            deq.pop_back();
            deq.push_front(temp);
            answer += 5;
            // 꽉차지않았다면
        } else {
            deq.push_front(temp);
            answer += 5;
        }
    }
    return answer;
}