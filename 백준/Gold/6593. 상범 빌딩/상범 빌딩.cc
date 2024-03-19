
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int z;
    int distance;
};


int main() {
    while(1) {
        int L, R, C;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        
        vector<vector<vector<char>>> map(R, vector<vector<char>>(C, vector<char>(L, '-')));
        vector<vector<vector<bool>>> visited(R, vector<vector<bool>>(C, vector<bool>(L, false)));
        string str;
        int startX, startY, startZ;
        int endX, endY, endZ;
        for (int k = 0; k < L; k++) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cin >> map[i][j][k];
                    if (map[i][j][k] == 'S') {
                        startX = i;
                        startY = j;
                        startZ = k;
                    }
                    if (map[i][j][k] == 'E') {
                        endX = i;
                        endY = j;
                        endZ = k;
                    }
                }
            }
            getline(cin, str);
        }
        queue<node> q;
        q.push({startX, startY, startZ, 0});
        visited[startX][startY][startZ] = true;
        
        int result = -1;
        int dx[6] = {-1, 0, 1, 0, 0, 0};
        int dy[6] = {0, 1, 0, -1, 0, 0};
        int dz[6] = {0, 0, 0, 0, 1, -1};
        while (!q.empty()) {
            auto s = q.front();
            if (s.x == endX && s.y == endY && s.z == endZ) {
                result = s.distance;
                break;
            }
            q.pop();
            
            for (int i = 0; i < 6; i++) {
                int nx = s.x + dx[i];
                int ny = s.y + dy[i];
                int nz = s.z + dz[i];
                
                if (nx < 0 || ny < 0 || nz < 0 || nx == R || ny == C || nz == L || map[nx][ny][nz] == '#') {
                    continue;
                }
                
                if (!visited[nx][ny][nz]) {
                    visited[nx][ny][nz] = true;
                    q.push({nx, ny, nz, s.distance + 1});
                }
            }
        }
        
        //Escaped in 11 minute(s).
        if (result != -1) {
            cout << "Escaped in " << result << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
        
    }
    
    
    return 0;
}
