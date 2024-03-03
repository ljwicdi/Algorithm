
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct node {
    int x;
    int y;
    int distance;
};
int main()
{
    string s;
    map<int, char> myMap;
    myMap[97] = 'a';
    myMap[98] = 'b';
    myMap[99] = 'c';
    myMap[100] = 'd';
    myMap[101] = 'e';
    myMap[102] = 'f';
    myMap[103] = 'g';
    myMap[104] = 'h';
    while (getline(cin, s)) {
        vector<vector<int>> v(8, vector<int>(8, 0));
        vector<vector<bool>> visited(8, vector<bool>(8, false));
        
        // 시작 행, 열
        int startRow = 7 - (s[1] - 49);
        int startCol = s[0] - 97;
        // 도착 행, 열
        int departureRow = 7 - (s[4] - 49);
        int departureCol = s[3] - 97;
        
        queue<node> q;
        node nd;
        nd.x = startRow;
        nd.y = startCol;
        nd.distance = 0;
        q.push(nd);
        visited[startRow][startCol] = true;
        
        int result = 0;
        int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int nx, ny;
        while (!q.empty()) {
            auto s = q.front();
            if (s.x == departureRow && s.y == departureCol) {
                result = s.distance;
                break;
            }
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                nx = s.x + dx[i];
                ny = s.y + dy[i];
                
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
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
        string str1, str2;
        str1 = myMap[s[0]] + to_string(s[1] - 48);
        str2 = myMap[s[3]] + to_string(s[4] - 48);
        cout << "To get from ";
        cout << str1;
        cout << " to ";
        cout << str2;
        cout << " takes ";
        cout << result;
        cout << " knight moves.\n";
        
    }

    return 0;
}
