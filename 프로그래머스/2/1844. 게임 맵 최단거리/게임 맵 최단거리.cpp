#include<vector>
#include<queue>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int solution(vector<vector<int> > maps) {
    int answer = -1;
    // 0 : 벽, 1 : 벽 없음
    vector<vector<bool>> visited (maps.size(), vector<bool> (maps[0].size(), false));
    int destinationX = maps.size() - 1;
    int destinationY = maps[0].size() - 1;
    
    queue<node> q;
    node start;
    start.x = 0; start.y = 0; start.distance = 1;
    visited[0][0] = true;
    q.push(start);
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nx, ny;
    while (!q.empty()) {
        auto currentNode = q.front();
        q.pop();
        if (currentNode.x == destinationX && currentNode.y == destinationY) {
            answer = currentNode.distance;
            break;
        }
        
        
        for (int i = 0; i < 4; i++) {
            nx = currentNode.x + dx[i];
            ny = currentNode.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size() || maps[nx][ny] == 0) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
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