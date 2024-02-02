#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main() {
    
    set<pair<int, int>> apple;  // 사과의 위치를 체크하기위해
    int N;
    cin >> N;
    vector<int> v[N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v[i].push_back(0);
        }
    }
    v[0][0] = 1;    // 현재 뱀의 위치
    
    int K;  // 사과의 개수
    cin >> K;
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        apple.insert(make_pair(x - 1, y - 1));
    }
    int D; // 방향 정보의 개수
    cin >> D;
    queue<pair<int, char>> q;
    int s;
    char DD;
    for (int i = 0; i < D; i++) {
        cin >> s >> DD;
        q.push(make_pair(s, DD));
    }
    
    int sec = 0;
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int currentDirection = 1;
    int headX = 0, headY = 0;
    queue<pair<int, int>> tail; // 꼬리 기록을 기록할 큐
    tail.push(make_pair(0, 0));
    while (1) {
        sec++; // 1초 증가
        
        // 현재 방향 대로 한걸음 움직임
        headX = headX + dx[currentDirection];
        headY = headY + dy[currentDirection];
        
        // 벽에 충돌하면 종료
        if (headX < 0 || headY < 0 || headX >= N || headY >= N) {
            break;
        } else if (v[headX][headY] == 1) {  // 자신의 몸에 부딪힘
            break;
        }
        
        // 사과가 없다면
        if (apple.find(make_pair(headX, headY)) == apple.end()) {
            v[tail.front().first][tail.front().second] = 0;    // 꼬리를 비워줌
            v[headX][headY] = 1;
            tail.pop();
            tail.push(make_pair(headX, headY));
        } else {    // 사과가 있다면
            apple.erase(make_pair(headX, headY));
            v[headX][headY] = 1;
            tail.push(make_pair(headX, headY));
        }
        
        // 다음 방향 체크
        if (sec == q.front().first) {
            if (q.front().second == 'L') {  // 왼쪽
                if (currentDirection == 0) {
                    currentDirection = 3;
                } else {
                    currentDirection--;
                }
            } else {    // 오른쪽
                if (currentDirection == 3) {
                    currentDirection = 0;
                } else {
                    currentDirection++;
                }
            }
            q.pop();
        }
    }
    
    cout << sec;
    return 0;
}
