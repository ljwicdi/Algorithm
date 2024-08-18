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

bool comp(node a, node b) {
    if (a.x < b.x) {
        return true;
    } else if (a.x == b.x) {
        if (a.y < b.y) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
};

int main() {
    
    int N, fishCnt = 0;
    pair<int, int> sharkPos;
    cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int data;
            cin >> data;
            if (data == 9) graph[i].push_back(0);
            else graph[i].push_back(data);
            
            if (data == 9) {
                sharkPos.first = i;
                sharkPos.second = j;
            }
            
            if (data != 9 && data != 0) {
                fishCnt++;
            }
        }
    }
    
    int sharkSize = 2, eaten = 0, result = 0;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool check = false;
    while (1) {
        queue<node> q;
        q.push({sharkPos.first, sharkPos.second, 0});
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[sharkPos.first][sharkPos.second] = true;
        check = false;
        vector<node> determineXy;
        int mi = -1;
        bool calchk = false;
        while (!q.empty()) {
            auto s = q.front();
            
            if (graph[s.x][s.y] != 0 && graph[s.x][s.y] < sharkSize) {
                if (mi == -1) {
                    mi = s.distance;
                    determineXy.push_back({s.x, s.y, s.distance});
                } else if (mi != -1 && s.distance != mi) {
                    
                    sort(determineXy.begin(), determineXy.end(), comp);
                    
                    int determineX = determineXy[0].x;
                    int determineY = determineXy[0].y;
                    graph[determineX][determineY] = 0;
                    eaten++;
                    sharkPos.first = determineX;
                    sharkPos.second = determineY;
                    result += determineXy[0].distance;
                    
                    if (sharkSize == eaten) {
                        eaten = 0;
                        sharkSize++;
                    }
                    
                    fishCnt--;
                    check = true;
                    calchk = true;
                    break;
                } else if (mi != -1 && s.distance == mi) {
                    determineXy.push_back({s.x, s.y, s.distance});
                }
            }
            
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dx[i];
                int ny = s.y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                    continue;
                }
                
                if (!visited[nx][ny]) {
                    if (graph[nx][ny] <= sharkSize) {
                        q.push({nx, ny, s.distance + 1});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        
        if (!calchk && determineXy.size() != 0) {
            sort(determineXy.begin(), determineXy.end(), comp);
            int determineX = determineXy[0].x;
            int determineY = determineXy[0].y;
            graph[determineX][determineY] = 0;
            eaten++;
            sharkPos.first = determineX;
            sharkPos.second = determineY;
            result += determineXy[0].distance;
                    
            if (sharkSize == eaten) {
                eaten = 0;
                sharkSize++;
            }
                    
            fishCnt--;
            check = true;
        }
        
        if (fishCnt == 0 || !check) {
            break;
        }
    }
    
    cout << result;

    return 0;
}