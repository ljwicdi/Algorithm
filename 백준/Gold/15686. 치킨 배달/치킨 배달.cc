#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int N, M;
int result = 999999;
vector<pair<int, int>> chi;
vector<pair<int, int>> home;
void bfs(vector<pair<int, int>> & selection) {
    
    vector<vector<int>> map(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<node> q;
    for (int i = 0; i < home.size(); i++) {
        map[home[i].first][home[i].second] = 1;
    }
    
    for (int i = 0; i < selection.size(); i++) {
        map[selection[i].first][selection[i].second] = 2;
        q.push({selection[i].first, selection[i].second, 0});
        visited[selection[i].first][selection[i].second] = true;
    }
    
    // 치킨집에서 multi source bfs
    
    int chiDistance = 0;
    int visitedCnt = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto s = q.front();
        
        if (map[s.x][s.y] == 1) {
            chiDistance += s.distance;
            visitedCnt++;
        }
        
        if (visitedCnt == home.size()) {
            break;
        }
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }
            
            if (!visited[nx][ny]) {
                q.push({nx, ny, s.distance + 1});
                visited[nx][ny] = true;
            }
        }
    }
    
    if (result > chiDistance) {
        result = chiDistance;
    }
}

void combination(int depth, int r, int current, vector<pair<int, int>> & selection) {
    if (depth == r) {
        bfs(selection);
        return;
    }
    
    for (int i = current + 1; i < chi.size(); i++) {
        selection.push_back(chi[i]);
        combination(depth + 1, r, i, selection);
        selection.pop_back();
    }
}


int main() {
    
    cin >> N >> M;
    
    vector<vector<int>> map(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                chi.push_back(make_pair(i, j));
            }
            if (map[i][j] == 1) {
                home.push_back(make_pair(i, j));
            }
        }
    }
    
    vector<pair<int, int>> selection;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < chi.size(); j++) {
            selection.push_back(chi[j]);
            combination(1, i, j, selection);    
            selection.pop_back();
        }
    }
    
    cout << result;
    return 0;
}