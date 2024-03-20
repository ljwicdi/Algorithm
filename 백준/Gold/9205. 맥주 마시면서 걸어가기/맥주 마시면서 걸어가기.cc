
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std; 

int main() {
    //  가장 가까운 편의점 부터 들리면서 전진 해나가자 
    //  근데 가장 가까운 편의점을 들림으로 인해 갈 수 있는 곳을 못가게 되는 경우가 생길 수도 ?
    // 큐에 편의점을 넣고 편의점끼리 옮겨 다니면 ? 
    // 편의점 방문체크 해줌
    // 동심원을 그리듯이.. 상근이의 집에서 먼저 갈 수 있는 편의점을 q에 다 넣고 확장하는 느낌?
    // 최단거리랑 비슷한데 ?
    
    int testCase;
    cin >> testCase;
  
    for (int i = 0; i < testCase; i++) {
        
        set<pair<int, int>> visited;    // 갔던 편의점은 다시 안감
        queue<pair<int, int>> q;
        
        int convinient; // 편의점 수
        cin >> convinient;
        
        int homeX, homeY;
        
        cin >> homeX >> homeY;
        
        int convinientX, convinientY;
        vector<pair<int, int>> convinientList;
        for (int j = 0; j < convinient; j++) {
            cin >> convinientX >> convinientY;
            convinientList.push_back(make_pair(convinientX, convinientY));
            if ((abs(convinientX - homeX) + abs(convinientY - homeY)) / 50.0 <= 20) {
                q.push(make_pair(convinientX, convinientY));
                visited.insert(make_pair(convinientX, convinientY));
            }
        }
        
        int festivalX, festivalY;
        
        cin >> festivalX >> festivalY;
        
        string result = "sad";
        
        if ((abs(homeX - festivalX) + abs(homeY - festivalY)) / 50.0 <= 20) {
            result = "happy";
        }
        while (!q.empty()) {
            auto s = q.front();
             
            if ((abs(s.first - festivalX) + abs(s.second - festivalY)) / 50.0 <= 20) {
                result = "happy";
                break;
            }
            q.pop();
            
            for (int j = 0; j < convinientList.size(); j++) {
                if (visited.find(make_pair(convinientList[j].first, convinientList[j].second)) == visited.end()) {
                    if ((abs(s.first - convinientList[j].first) + abs(s.second - convinientList[j].second)) / 50.0 <= 20) {
                        q.push(make_pair(convinientList[j].first, convinientList[j].second));
                        visited.insert(make_pair(convinientList[j].first, convinientList[j].second));
                    }
                }
            }
        }
        
        
        cout << result << "\n";
        
    }
    return 0;
}
