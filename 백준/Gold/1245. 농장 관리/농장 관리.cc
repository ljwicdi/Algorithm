
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int x;
    int y;
    int value;
};

bool comp(node a, node b) {
    if (a.value > b.value) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<node> sortV;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            node nd;
            nd.x = i;
            nd.y = j;
            nd.value = map[i][j];
            sortV.push_back(nd);
        }
    }
    
    sort(sortV.begin(), sortV.end(), comp);
    int result = 0;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int i = 0; i < sortV.size(); i++) {
        if (visited[sortV[i].x][sortV[i].y] == false) {
            result++;
            
            visited[sortV[i].x][sortV[i].y] = true;
            queue<pair<int, int>> q;
            q.push(make_pair(sortV[i].x, sortV[i].y));
            while (!q.empty()) {
                auto s = q.front();
                q.pop();
                
                for (int j = 0; j < 8; j++) {
                    int nx = s.first + dx[j];
                    int ny = s.second + dy[j];
                    
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] > map[s.first][s.second]) {
                        continue;
                    }
                    
                    if (visited[nx][ny] == false) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            
        }
    }
    
    cout << result;
    return 0;
}
