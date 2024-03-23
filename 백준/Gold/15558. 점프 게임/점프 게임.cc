
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
    int N, K;
    cin >> N >> K;
    vector<vector<int>> v(2, vector<int>(N, 0));
    vector<vector<bool>> visited(2, vector<bool>(N, false));    
    string str;
    for (int i = 0; i < 2; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                v[i][j] = 1;
            }
        }
    }
    
    queue<node> q;
    node nd;
    nd.x = 0;
    nd.y = 0;
    nd.distance = 0;
    q.push(nd);
    visited[0][0] = true;
    int result = 0;
    
    while (!q.empty()) {
        auto s = q.front();
        
        q.pop();
        
        if (s.y + 1 >= N) {
            result = 1;
            break;
        }
        if (visited[s.x][s.y + 1] == false &&  v[s.x][s.y + 1] != 0) {
            visited[s.x][s.y + 1] = true;
            node nd;
            nd.x = s.x;
            nd.y = s.y + 1;
            nd.distance = s.distance + 1;
            q.push(nd);
        }
        
        if (visited[s.x][s.y - 1] == false && s.y - 1 >= 0 && v[s.x][s.y - 1] != 0 && s.y - 1 >= s.distance + 1) {
            visited[s.x][s.y - 1] = true;
            node nd;
            nd.x = s.x;
            nd.y = s.y - 1;
            nd.distance = s.distance + 1;
            q.push(nd);
        }
        
        if (s.y + K >= N) {
            result = 1;
            break;
        }
        
        if (s.x == 0) {
            if (visited[1][s.y + K] == false && v[1][s.y + K] != 0) {
                visited[1][s.y + K] = true;
                node nd;
                nd.x = 1;
                nd.y = s.y + K;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        } else if (s.x == 1) {
            if (visited[0][s.y + K] == false && v[0][s.y + K] != 0) {
                visited[0][s.y + K] = true;
                node nd;
                nd.x = 0;
                nd.y = s.y + K;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
    }
    
    cout << result;
    return 0;
}
