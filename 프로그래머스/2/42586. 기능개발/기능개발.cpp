#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < progresses.size(); i++) {
        q.push(make_pair(progresses[i], speeds[i]));
    }
    
    while (!q.empty()) {
        if (q.front().first >= 100) {
            int cnt = 0;
            while (!q.empty() && q.front().first >= 100) {
                q.pop();
                cnt++;
            }
            answer.push_back(cnt);
            continue;
        }
        vector<pair<int, int>> temp;
        while (!q.empty()) {
            pair<int, int> n = q.front();
            if (n.first < 100) {
                n.first = n.first + n.second;
            }
            temp.push_back(n);
            q.pop();
        }
        
        for (int i = 0; i < temp.size(); i++) {
            q.push(temp[i]);
        }
    }
    
    return answer;
}