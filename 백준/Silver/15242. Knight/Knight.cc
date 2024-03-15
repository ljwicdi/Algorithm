
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};

int main()
{
    string start, end;
    cin >> start;
    cin >> end;
    
    int startRow = 8 - (start[1] - '0');
    int startCol = start[0] - 97;
    int departureRow = 8 - (end[1] - '0');
    int departureCol = end[0] - 97;
    
    vector<vector<int>> v(8, vector<int>(8, 0));
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    
    queue<node> q;
    node nd;
    nd.x = startRow;
    nd.y = startCol;
    nd.distance = 0;
    q.push(nd);
    visited[startRow][startCol] = true;
    
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    int result = 0;
   
    while(!q.empty()) {
        auto s = q.front();
        if (s.x == departureRow && s.y == departureCol) {
            result = s.distance;
            break;
        }
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];
            
            if (nx < 0 || nx >= 8 || ny < 0 || ny >=  8) {
                continue;
            }
            
            if (visited[nx][ny] == false) {
                visited[nx][ny] = true;
                node nd;
                nd.x = nx;
                nd.y = ny;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
    }
    
    cout << result;
    return 0;
}
