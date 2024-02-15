#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int N, M;
    cin >> N >> M;  // N * N, M = 상대 말의 수
    vector<vector<pair<int, int>>> v(N, vector<pair<int, int>>(N, {0, 0}));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    int X, Y;   // 나의 좌표
    cin >> X >> Y;

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        v[A - 1][B - 1] = make_pair(1, i + 1); // 1, i번째
    }

    queue<node> q;
    node start;
    start.x = X - 1;
    start.y = Y - 1;
    start.distance = 0;
    q.push(start);
    visited[X - 1][Y - 1] = true;

    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    vector<pair<int, int>> result;

    while (!q.empty()) {
        node current = q.front();
        q.pop();

        if (v[current.x][current.y].first == 1) {
            result.push_back({v[current.x][current.y].second, current.distance});
        }

        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                node next;
                next.x = nx;
                next.y = ny;
                next.distance = current.distance + 1;
                q.push(next);
            }
        }
    }

    sort(result.begin(), result.end(), comp);

    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i].second;
        } else {
            cout << result[i].second << " ";
        }
    }

    return 0;
}
