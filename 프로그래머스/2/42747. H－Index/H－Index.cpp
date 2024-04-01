#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int result = 0;
    
    int m = citations[citations.size() - 1];
    sort(citations.begin(), citations.end());
    
    while(1) {
        int cnt = 0;
        if (answer > m) {
            break;
        }
        for (int i = 0; i < citations.size(); i++) {
            if (answer <= citations[i]) {
                cnt++;
            }
            if (answer <= cnt) {
                result = answer;
            }
        }
        answer++;
    }
    
    return result;
}