#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct node {
    int x;
    int y;
    int distance;
    int startValue;
};

struct des {
    int distance;
    int value;
    int start;
};

bool comp(des a, des b) {
    if (a.distance > b.distance) {
        return true;
    } else if (a.distance == b.distance) {
        if ((a.value + a.start) > (b.value + b.start)) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
        }
    }
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int maxDistance = -1;
    int maxValue = 0;
    int start;
    vector<des> distanceAndValue;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (v[i][j] == 0) continue;
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            queue<node> q;
            q.push({i, j, 0, v[i][j]});
            visited[i][j] = true;
            start = v[i][j];
            // 출발점에서 가장 먼 거리의 지점을 구해야함 
            // 거리, 값
            
            while (!q.empty()) {
                auto s = q.front();
                distanceAndValue.push_back({s.distance, v[s.x][s.y], start});
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int nx = s.x + dx[k];
                    int ny = s.y + dy[k];
                    
                    if (nx < 0 || ny < 0 || nx >= row || ny >= col || v[nx][ny] == 0) {
                        continue;
                    }
                    
                    if (visited[nx][ny] == false) {
                        visited[nx][ny] = true;
                        
                        q.push({nx, ny, s.distance + 1});
                    }
                }
            }
        }
    }
    
    sort(distanceAndValue.begin(), distanceAndValue.end(), comp);
    
    cout << distanceAndValue[0].value + distanceAndValue[0].start;
    
    return 0;
}
