#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    // 0번 인덱스 부터 마지막 인덱스 까지 
    // 각 인덱스는 + 와 -의 두가지 경우가 존재한다. (이 경우들은 서로 중복되지않음)
    // 총 2^n 경우가 존재하고 
    // 각각의 경우의 누적합을 구해준다. 
    // 마지막 인덱스 까지 계산 했을 때 target과 같으면 개수 증가
    int answer = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.second == numbers.size()) {
            if (target == s.first) {
                answer++;
            }
            q.pop();
            continue;
        }
        q.pop();
        q.push(make_pair(s.first + numbers[s.second], s.second + 1));
        q.push(make_pair(s.first - numbers[s.second], s.second + 1));
        
    }
    return answer;
}