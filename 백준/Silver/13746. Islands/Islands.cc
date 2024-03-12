
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    
    vector<vector<char>> v(row, vector<char>(col, 'F'));
    vector<vector<bool>> visited(row, vector<bool> (col, false));
    char data;
  
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
           
        }
    }
    
    
    
    int i = 0, j = 0;
    int islandCount = 0;
    while (1) {
        while (1) {
            if (v[i][j] == 'L' && visited[i][j] == false) {
                break;
            } 
            
            j++;
            
            if (j == col) {
                j = 0;
                i++;
            }
            if (i == row) {
                break;
            }
        }
        if (i == row) {
            break;
        }
        
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        islandCount++;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            
            
            for (int k = 0; k < 4; k++) {
                int nx = s.first + dx[k];
                int ny = s.second + dy[k];
                
                if (nx < 0 || nx == row || ny < 0 || ny == col || v[nx][ny] == 'W') {
                    continue;
                }
                
                if (visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    cout << islandCount;
    return 0;
}
