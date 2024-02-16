#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0; // 섞는 횟수
    priority_queue<int, vector<int>, greater<int>> pq; // min heap 생성
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    int chk = 0;
    while (!pq.empty()) {
        if (pq.top() >= K) {
            chk = 1;
            break;
        }
        
        if (pq.size() >= 2) {
            int mFirst = pq.top();
            pq.pop();
            int mSecond = pq.top();
            pq.pop();
            int newScoville = mFirst + mSecond * 2;
            pq.push(newScoville);
            answer++;
        } else {
            break;
        }
        
    }
    
    if (chk == 0) {
        answer = -1;
    }
    return answer;
}