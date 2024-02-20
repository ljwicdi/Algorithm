#include<vector>
#include<queue>
using namespace std;

// X, Y 좌표, 현재까지 이동한 거리가 담긴 노드 
struct node {
    int x;
    int y;
    int distance;
};

int solution(vector<vector<int> > maps) {
    int answer = -1;
    // 0 : 벽, 1 : 벽 없음
    vector<vector<bool>> visited (maps.size(), vector<bool> (maps[0].size(), false));
    
    // 도착 X, Y 좌표
    int destinationX = maps.size() - 1;
    int destinationY = maps[0].size() - 1;
    
    queue<node> q;
    // 처음 시작한 위치는 X = 0, Y = 0, 거리 = 1 이다 (거리 1인 이유는 출발지도 이동거리에 포함하기 때문)
    // 시작 노드를 큐에 담음 
    node start;
    start.x = 0; start.y = 0; start.distance = 1;
    visited[0][0] = true;
    q.push(start);
    
    // 북, 동, 남, 서
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    while (!q.empty()) {
        // 현재 탐색 노드 
        auto currentNode = q.front();
        q.pop();
        // 현재 탐색 노드가 도착 지점에 도달했다면 이 노드가 현재까지 진행한 거리를 반환
        if (currentNode.x == destinationX && currentNode.y == destinationY) {
            answer = currentNode.distance;
            break;
        }
        
        
        for (int i = 0; i < 4; i++) {
            // 다음 탐색할 X, Y 좌표
            nx = currentNode.x + dx[i];
            ny = currentNode.y + dy[i];
            
            // 만약 다음 탐색할 곳이 진영 밖이거나 벽이라면 탐색 안함
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size() || maps[nx][ny] == 0) {
                continue;
            }
            
            // 아직까지 방문하지 않은 좌표라면 탐색
            if (visited[nx][ny] == false) {
                // 방문표시 하고
                visited[nx][ny] = true;
                // 현재 탐색 노드의 거리 + 1 을 기록한 노드를 큐에 삽입
                node nextNode;
                nextNode.x = nx;
                nextNode.y = ny;
                nextNode.distance = currentNode.distance + 1;
                q.push(nextNode);
            }
        }
        
    }
        
    return answer;
}