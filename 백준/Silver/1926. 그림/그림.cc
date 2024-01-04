
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

bool ChkEastWall (int x, int y, int width) {
    if (y == width - 1) {
        return false;
    }
    else {
        return true;
    }
}

bool ChkNorthWall (int x, int y) {
    if (x == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool ChkWestWall (int x, int y) {
    if (y == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool ChkSouthWall (int x, int y, int height) {
    if (x == height - 1) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    
    int n, m, data;
     // false 초기화
    cin >> n >> m;
    vector<int> picture[n];
    vector<bool> visited[n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> data;
            picture[i].push_back(data);
            visited[i].push_back(false);
        }
    }
    
    int cnt = 0;
    int i = 0, j = 0;
    int max = 0;
    set<pair<int, int>> mySet;
    while (1) {
        queue < vector<int> > q;  // (x, y), distance
        
        while (1) {
            if (visited[i][j] == false && picture[i][j] == 1) {
                break;
            }
            j++;
            
            if (j == m) {
                j = 0;
                i++;
            }
            
            if (i == n) {
                break;
            }
        }
        
        if (i == n) {
            break;
        }
        q.push(vector<int> {i, j});
        mySet.insert(make_pair(i, j));
        cnt++;
        int temp = 0;
        
        while (!q.empty()) {
            auto s = q.front();
            if(visited[s[0]][s[1]] == false) {
                temp++;
            }
            visited[s[0]][s[1]] = true;
            q.pop();
           
            
            
            // 동
            if (ChkEastWall (s[0], s[1], m)) {
                if (!visited[s[0]][s[1] + 1] && picture[s[0]][s[1] + 1] == 1) {
                    if (mySet.find (make_pair (s[0], s[1] + 1)) == mySet.end()) {
                         q.push(vector<int> {s[0], s[1] + 1});
                         mySet.insert(make_pair (s[0], s[1] + 1));
                    }
                }
            }
            
            if (ChkNorthWall (s[0], s[1])) {
                if (!visited[s[0] - 1][s[1]] && picture[s[0] - 1][s[1]] == 1) {
                    if (mySet.find (make_pair (s[0] - 1, s[1])) == mySet.end()) {
                         q.push(vector<int> {s[0] - 1, s[1]});
                         mySet.insert(make_pair (s[0] - 1, s[1]));
                    }
                }
            }
            
            if (ChkWestWall (s[0], s[1])) {
                if (!visited[s[0]][s[1] - 1] && picture[s[0]][s[1] - 1] == 1) {
                    if (mySet.find (make_pair (s[0], s[1] - 1)) == mySet.end()) {
                         q.push(vector<int> {s[0], s[1] - 1});
                         mySet.insert(make_pair (s[0], s[1] - 1));
                    }
                }
            }
            
            if (ChkSouthWall (s[0], s[1], n)) {
                if (!visited[s[0] + 1][s[1]] && picture[s[0] + 1][s[1]] == 1) {
                    if (mySet.find (make_pair (s[0] + 1, s[1])) == mySet.end()) {
                         q.push(vector<int> {s[0] + 1, s[1]});
                         mySet.insert(make_pair (s[0] + 1, s[1]));
                    }
                }
            }
        }
        
        if (max < temp) {
            max = temp;
        }
    }
    
    cout << cnt << "\n" << max;
    return 0;
}
