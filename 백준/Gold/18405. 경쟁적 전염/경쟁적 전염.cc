#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct node {
    int x;
    int y;
    int ditance;
    int value;
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(N, vector<int>(N, 0));
    queue<node> q;
    set<pair<int, int>> zero;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
            if (v[i][j] != 0) {
                q.push({i, j, 0, v[i][j]});
            }
            if (v[i][j] == 0) {
                zero.insert(make_pair(i, j));
            }
        }
    }
    
    int S, X, Y;
    cin >> S >> X >> Y;
    
    int result = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int currentT = 0;
    vector<pair<int, int>> temp;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.ditance == currentT + 1) {
            currentT += 1;
            
            for (auto k : temp) {
                zero.erase(make_pair(k.first, k.second));
            }
            vector<pair<int, int>> temp;
        }
        
        if (s.ditance >= S) {
            result = v[X - 1][Y - 1];
            break;
        }
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || (v[nx][ny] != 0 && s.value >= v[nx][ny])
            || zero.find(make_pair(nx, ny)) == zero.end()) {
                continue;
            }
            
            if (v[nx][ny] != 0 && s.value < v[nx][ny]) {
                v[nx][ny] = s.value;
                q.push({nx, ny, s.ditance + 1, s.value});
                temp.push_back(make_pair(nx, ny));
            } else if (v[nx][ny] == 0) {
                v[nx][ny] = s.value;
                q.push({nx, ny, s.ditance + 1, s.value});
                temp.push_back(make_pair(nx, ny));
            }
        }
        
        
    }
    
   
    result = v[X - 1][Y - 1];
    cout << result;

    return 0;
}
