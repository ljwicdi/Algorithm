#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    // 처음에 map으로 풀었는데 하나의 경우가 시간초과가 나왔는데
    // 생각해보니 N^2 * logN 이라서 그런 것 같음
    
    
    // 한명만 완주하지 못했기 때문에
    // 정렬을 하고 앞에서부터 탐색해보면 처음으로 달라진 시점이 존재함
    // ex) a b c d e
    //     a b d e  (c 선수가 완주 못한 경우)
    // 이런 경우 3번째 인덱스에서 처음으로 달라짐 
    // 이것은 참가한 모든 선수중 이 선수가 빠졌다는 뜻임 
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    // 이 풀이에서 예외가 존재함 (동명이인이 존재하기 때문)
    // 예를 들어
    // a a a a a
    // a a a a  인 경우나
    // a a a a b
    // a a a a 인 경우가 존재하기 때문에 마지막에 ""를 넣어줌 
    // 넣어주지 않으면 인덱스 참조 오류가 발생함 
    completion.push_back("");
    for (int i = 0; i < participant.size(); i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    } 
    
     
    return answer;
}