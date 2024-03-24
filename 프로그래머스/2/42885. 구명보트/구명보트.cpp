#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end());
    for (int i = 0; i < people.size(); i++) {
        dq.push_back(people[i]);
    }
    
    while (!dq.empty()) {
        if (dq.size() == 1) {
            answer++;
            break;
        } else {
            if (dq.front() + dq.back() <= limit) {
                answer++;
                dq.pop_front();
                dq.pop_back();
            } else {
                dq.pop_back();
                answer++;
            }
        }
    }
    return answer;
}