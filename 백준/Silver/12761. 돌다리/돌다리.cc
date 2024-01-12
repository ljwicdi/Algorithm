
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int A, B, N, M;
    cin >> A >> B >> N >> M;
    
    int result; // 결과 횟수를 닮을 변수
    set<int> mySet; // 위치 중복 검사 위한 set
    queue<pair<int, int>> q;
    mySet.insert(N);
    q.push(make_pair(N, 0));  // 현재위치, 횟수
    while (!q.empty()) {    // 항상 도달 가능한 케이스만 주어짐
        auto s = q.front();  // 현재 탐색 중인 위치, 현재까지 이동한 횟수
        if (s.first == M) {   // 도착 했을 때
            result = s.second;
            break;
        }
        q.pop();
        
        if (s.first + 1 <= 100000 && mySet.find(s.first + 1) == mySet.end()) {   // +1 칸
            mySet.insert(s.first + 1);
            q.push(make_pair(s.first + 1, s.second + 1));
        }
        
        if (s.first - 1 >= 0 && mySet.find(s.first - 1) == mySet.end()) {   // - 1 칸
            mySet.insert(s.first - 1);
            q.push(make_pair(s.first - 1, s.second + 1));
        }
        
        if (s.first - A >= 0 && mySet.find(s.first - A) == mySet.end()) {   // - A 칸
            mySet.insert(s.first - A);
            q.push(make_pair(s.first - A, s.second + 1));
        }
        
        if (s.first - B >= 0 && mySet.find(s.first - B) == mySet.end()) {   // - B 칸
            mySet.insert(s.first - B);
            q.push(make_pair(s.first - B, s.second + 1));
        }
        
        if (s.first + A <= 100000 && mySet.find(s.first + A) == mySet.end()) {   // +A 칸
            mySet.insert(s.first + A);
            q.push(make_pair(s.first + A, s.second + 1));
        }
        
        if (s.first + B <= 100000 && mySet.find(s.first + B) == mySet.end()) {   // +B 칸
            mySet.insert(s.first + B);
            q.push(make_pair(s.first + B, s.second + 1));
        }
        
        if (s.first * A <= 100000 && mySet.find(s.first * A) == mySet.end()) {   // *A 칸
            mySet.insert(s.first * A);
            q.push(make_pair(s.first * A, s.second + 1));
        }
        
        if (s.first * B <= 100000 && mySet.find(s.first * B) == mySet.end()) {   // *B 칸
            mySet.insert(s.first * B);
            q.push(make_pair(s.first * B, s.second + 1));
        }
    }
    
    cout << result;

    return 0;
}
