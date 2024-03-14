#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    // 명령의 수 만큼 탐색
    for (int i = 0; i < commands.size(); i++) {
        // 어디서부터 ~ ?
        int startIndex = commands[i][0] - 1;
        // 여기까지 
        int endIndex = commands[i][1] - 1;
        // 몇번째를 찾을 것인가? 
        int k = commands[i][2];
        
        // startIndex 부터 endIndex 까지 담음 
        vector<int> temp;
        for (int j = startIndex; j <= endIndex; j++) {
            temp.push_back(array[j]);
        }
        // 정렬
        sort(temp.begin(), temp.end());
        
        // k번째수는 ?
        int kthNum = temp[k - 1];
        // 결과값 넣기
        answer.push_back(kthNum);
        
    }
    return answer;
}