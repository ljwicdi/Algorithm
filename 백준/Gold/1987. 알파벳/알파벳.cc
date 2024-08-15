#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C;
int result = 1;
void solve(int x, int y, vector<vector<char>> & board, vector<bool> & visited, int cnt) {
    
    if (result < cnt) {
        result = cnt;
    }
    
    // 현재 밟고 있는 위치에 존재하는 알파벳이 이미 밟은 알파벳이라면 
    if (visited[board[x][y] - 65]) {
    
        return;
    }
    
    visited[board[x][y] - 65] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[board[nx][ny] - 65]) {
            continue;
        }
        
        solve(nx, ny, board, visited, cnt + 1);
        visited[board[nx][ny] - 65] = false;
         
    }
}

int main() {
    
    cin >> R >> C;
    
    vector<vector<char>> board(R, vector<char>(C, '-'));
    vector<bool> visited(26, false);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(0, 0, board, visited, 1);
    
    cout << result;

    return 0;
}