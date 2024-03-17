
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
vector<int> answer;

int stateToInt(vector<vector<int>>& state) {
    int num = 0;
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state[i].size(); ++j) {
            num = num * 10 + state[i][j];
        }
    }
    return num;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    
    int data;
    for (int i = 0; i < 8; i++) {
        cin >> data;
        answer.push_back(data);
    }
    vector<vector<int>> qb(2, vector<int> (4, 0));
    qb[0] = {1, 2, 3, 4};
    qb[1] = {8, 7, 6, 5};
    
    queue<pair<vector<vector<int>>, int>> q;
    q.push(make_pair(qb, 0));
    
    unordered_set<int> visited;
    int result = 0;
    
    while (!q.empty()) {
        auto s = q.front();
        
        int stateNum = stateToInt(s.first); // 현재 상태를 정수로 변환
        if (visited.find(stateNum) != visited.end()) {
            q.pop();
            continue; // 이미 방문한 상태이면 다음으로 넘어감
        }
        visited.insert(stateNum); // 방문한 상태를 저장
        
        
        bool isDif = false;
        
        for (int i = 0; i < 4; i++) {
            if (answer[i] != s.first[0][i]) {
                isDif = true;
            }
        }
        if (answer[4] != s.first[1][3]) isDif = true;
        if (answer[5] != s.first[1][2]) isDif = true;
        if (answer[6] != s.first[1][1]) isDif = true;
        if (answer[7] != s.first[1][0]) isDif = true;
        if (isDif == false) {
            result = s.second;
            break;
        }
        
        q.pop();
        
        vector<vector<int>> k = s.first;
        vector<vector<int>> temp(2, vector<int>(4, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                temp[i][j] = k[i][j];
            }
        }
        // 1번 
        int tempInt;
        tempInt = temp[1][0]; temp[1][0] = temp[0][0]; temp[0][0] = tempInt;
        tempInt = temp[1][1]; temp[1][1] = temp[0][1]; temp[0][1] = tempInt;
        tempInt = temp[1][2]; temp[1][2] = temp[0][2]; temp[0][2] = tempInt;
        tempInt = temp[1][3]; temp[1][3] = temp[0][3]; temp[0][3] = tempInt;
        q.push(make_pair(temp, s.second + 1));
        
       
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                temp[i][j] = k[i][j];
            }
        }
        
        // 2번 
        int tempInt2;
        tempInt = temp[0][1]; temp[0][1] = temp[0][0]; tempInt2 = temp[0][2]; temp[0][2] = tempInt; 
        tempInt = temp[0][3]; temp[0][3] = tempInt2; temp[0][0] = tempInt; 
        tempInt = temp[1][1]; temp[1][1] = temp[1][0]; tempInt2 = temp[1][2]; temp[1][2] = tempInt; 
        tempInt = temp[1][3]; temp[1][3] = tempInt2; temp[1][0] = tempInt; 
        q.push(make_pair(temp, s.second + 1));
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                temp[i][j] = k[i][j];
            }
        }
        
        // 3번
        tempInt = temp[0][1];
        temp[0][1] = temp[0][2];
        tempInt2 = temp[1][1];
        temp[1][1] = tempInt;
        tempInt = temp[1][2];
        temp[1][2] = tempInt2;
        temp[0][2] = tempInt;
        q.push(make_pair(temp, s.second + 1));
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                temp[i][j] = k[i][j];
            }
        }
        
        // 4번
        tempInt = temp[1][3];
        temp[1][3] = temp[0][0];
        temp[0][0] = tempInt;
         q.push(make_pair(temp, s.second + 1));
        
        
    }
    
    cout << result;
    return 0;
}
