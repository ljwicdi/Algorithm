#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로로 쭉 기냐, 쌓아올리냐? 
    // 약수
    int bottom = yellow;
    while (1) {
        if (yellow % bottom == 0) {
            int ma, mi;
            if (bottom > (yellow / bottom)) {
                ma = bottom;
                mi = yellow/bottom;
            } else {
                ma = yellow/bottom;
                mi = bottom;
            }
            if (brown == 2 * (ma + 2) + 2 * mi ) {
                answer.push_back(ma + 2);
                answer.push_back(mi + 2);
                break;
            }
        }
        bottom--;
        if (bottom == 0) break;
    }
    
    return answer;
}