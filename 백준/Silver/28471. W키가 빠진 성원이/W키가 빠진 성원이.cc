#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

struct node {
    int x;
    int y;
    int distance;
};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    scanf("%d", &N);

    vector<vector<char>> v(N, vector<char>(N));
    int startX, startY;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &v[i][j]);
            if (v[i][j] == 'F') {
                startX = i;
                startY = j;
            }
        }
    }

    queue<node> q;
    node nd = {startX, startY, 0};
    q.push(nd);

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[startX][startY] = true;

    int result = -1;
    // 서 
    int dx[] = {-1, -1, 0, 1, 1, 0, -1};
    int dy[] = {0, -1, -1, -1, 1, 1, 1};

    while (!q.empty()) {
        auto s = q.front();
        result++;
        q.pop();

        for (int i = 0; i < 7; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny] && v[nx][ny] == '.') {
                node next = {nx, ny, s.distance + 1};
                q.push(next);
                visited[nx][ny] = true;
            }
        }
    }

    printf("%d", result);
    return 0;
}
