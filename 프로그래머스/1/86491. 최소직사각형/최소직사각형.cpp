#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> small, big;
    
    // 모든 카드의 가로와 세로 중 짧은 것들 중 가장 큰 값과
    // 모든 카드의 가로와 세로 중 긴 것들 중 가장 큰 값을
    // 곲하면 그 넓이는 다른 모든 카드의 넓이를 덮을 수 있다.
    
    for (int i = 0; i < sizes.size(); i++) {
        // 가로, 세로 중 짧은 것들을 저장 
        if (sizes[i][0] < sizes[i][1]) {
            small.push_back(sizes[i][0]);
            big.push_back(sizes[i][1]);
        } else {
            // 가로, 세로 중 긴 것들을 저장 
            small.push_back(sizes[i][1]);
            big.push_back(sizes[i][0]);
        }
    }
    
    // 가장 짧은 것들, 가장 긴 것들을 각각 정렬 함 (디폴트는 오름차순)
    sort(small.begin(), small.end());
    sort(big.begin(), big.end());
    
    // 각각의 배열 마지막값이 가장 큰 값이므로 
    // 두 배열의 마지막 값들을 곱함 
    int answer = small[small.size() - 1] * big[big.size() - 1];
    return answer;
}