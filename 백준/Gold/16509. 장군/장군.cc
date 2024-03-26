#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int kingX, kingY;
struct node {
    int x;
    int y;
    int distance;
};

struct route {
    vector<int> x;
    vector<int> y;
};
// 가는 경로에 왕이 존재하는 지 체크
bool check(int flag, int currentX, int currentY) {
    route a[8] = {
        {{0, -1}, {-1, -2}},
        {{-1, -2}, {0, -1}},
        {{-1, -2}, {0, 1}},
        {{0, -1}, {1, 2}},
        {{0, 1}, {1, 2}},
        {{1, 2}, {0, 1}},
        {{1, 2}, {0, -1}},
        {{0, 1}, {-1, -2}}
    };
    
    for (int i = 0; i < 2; i++) {
        int nx = currentX + a[flag].x[i];
        int ny = currentY + a[flag].y[i];
        
        if (nx == kingX && ny == kingY) {
            return false;
        }
    }
    return true;
}
using namespace std;
int main()
{
    int startX, startY;
    cin >> startX >> startY;
    
    cin >> kingX >> kingY;
    
    queue<node> q;
    q.push({startX, startY, 0});
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(startX, startY));
    int result = -1;
    int dx[8] = {-2, -3, -3, -2, 2, 3, 3, 2};
    int dy[8] = {-3, -2, 2, 3, 3, 2, -2, -3};
    while (!q.empty()) {
        auto s = q.front();
        if (s.x == kingX && s.y == kingY) {
            result = s.distance;
            break;
        }
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx > 9 || ny > 8 || !check(i, s.x, s.y)) {
                continue;
            }
            
            if (mySet.find(make_pair(nx, ny)) == mySet.end()) {
                mySet.insert(make_pair(nx, ny));
                q.push({nx, ny, s.distance + 1});
            }
        }
    }
    
    cout << result;
    return 0;
}
