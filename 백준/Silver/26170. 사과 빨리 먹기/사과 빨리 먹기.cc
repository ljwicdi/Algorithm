
#include <iostream>
#include <vector>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> v[5];
int m = 9999;
void dfs(int x, int y, vector<bool> visited[], int distance, int appleCnt) {
    vector<bool> vv[5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vv[i].push_back(visited[i][j]);
        }
    }
    vv[x][y] = true;
    int apple;
    
    if (v[x][y] == 1) {
        apple = appleCnt + 1;
    } else {
        apple = appleCnt;
    }
    
    if (apple == 3) {
        if (m > distance) {
            m = distance;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || v[nx][ny] == -1) {
            continue;
        } 
        
        if (vv[nx][ny] == false) {
            dfs(nx, ny, vv, distance + 1, apple);
        }
    }
}

int main()
{
    
    vector<bool> visited[5];
    int data;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> data;
            v[i].push_back(data);
            visited[i].push_back(false);
        }
    }
    
    int r, c;
    cin >> r >> c;
    
    dfs(r, c, visited, 0, 0);
    
    if (m == 9999) {
        cout << "-1";
    } else {
        cout << m;
    }
    return 0;
}
