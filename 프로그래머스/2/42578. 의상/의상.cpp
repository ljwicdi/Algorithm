#include <string>
#include <vector>
#include <map>
using namespace std;
// 시간 초과 
// void combination(vector<bool> & visited, int next, int n, int r, vector<pair<string, int>> & v) {
//     if (r == 0) {
//         int gob = 1;
//         for (int i = 0; i < visited.size(); i++) {
//             if (visited[i] == true) {
//                 gob = gob * v[i].second;
//             }
//         }
//         answer = answer + gob;
//         return;
//     }
    
//     if (next >= n) return;
//     visited[next] = true;
//     combination(visited, next + 1, n, r - 1, v); // 현재 아이템을 선택하는 경우
//     visited[next] = false;
//     combination(visited, next + 1, n, r, v); // 현재 아이템을 선택하지 않는 경우
   
// }
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    // <옷 종류, 옷 개수>
    map<string, int> myMap;
    for (int i = 0; i < clothes.size(); i++) {
        if (myMap.find(clothes[i][1]) == myMap.end()) {
            myMap[clothes[i][1]] = 1;
        } else {
            myMap[clothes[i][1]]++;
        }
    }
    
    int gob = 1;
    for (auto s : myMap) {
        gob = gob * (s.second + 1);
    }
    answer = gob - 1;
    // // 조합으로 종류들을 선택하기 
    // vector<pair<string, int>> v(myMap.begin(), myMap.end());
    // for (int r = 1; r <= myMap.size(); r++) {
    //     // nCr
    //     vector<bool> visited(v.size(), false);
    //     combination(visited, 0, v.size(), r, v);
    // }
    
    
    return answer;
}