#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void init(vector<vector<int>> & map, int N, int M) {
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                map[i][j] = 0;
            }
        }
    }
}

void outerO2Fill(vector<vector<int>> & map, int N, int M) {
   
    // (0, 0) 은 항상 외부 공기
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
   
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
       
        for (int i = 0; i < 4; i++) {
            int nx = s.first + dx[i];
            int ny = s.second + dy[i];
           
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] != 0) {
                continue;
            }
           
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                map[nx][ny] = 2;
            }
        }
    }
   
}

void meltCheese(vector<vector<int>> & map, int N, int M, int & cheeseNum) {
   
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                   
                    if (map[nx][ny] == 2) {
                        cnt++;
                    }
                }
               
                if (cnt >= 2) {
                    map[i][j] = 0;
                    cheeseNum--;
                }
            }
        }
    }
}

int main() {
   
    int N, M, cheeseNum = 0;
    cin >> N >> M;
    vector<vector<int>> map(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int data;
            cin >> data;
            map[i].push_back(data);
           
            if (data == 1) {
                cheeseNum++;
            }
        }
    }
   
    if (cheeseNum == 0) {
        cout << 0;
        return 0;
    }
   
    int result = 0;
    while (1) {
        init(map, N, M);    
        outerO2Fill(map, N, M);
        meltCheese(map, N, M, cheeseNum);
        result++;
       
        if (cheeseNum == 0) {
            break;
        }
    }
   
    cout << result;

    return 0;
}