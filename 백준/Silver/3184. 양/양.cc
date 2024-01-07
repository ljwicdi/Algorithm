
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int R, C;

bool chkEastWall(int x, int y) {
    if (y == C - 1) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthWall(int x, int y) {
    if (x == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkWestWall(int x, int y) {
    if (y == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthWall(int x, int y) {
    if (x == R - 1) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    // 길 : 0, 울타리 : 1, 양 : 2, 늑대 : 3 
    
    char data;
    cin >> R >> C;
    
    vector<int> v[R];
    vector<bool> visited[R];
    set<pair<int, int>> mySet;
    int totalSheepNum = 0, totalWolfNum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> data;
            
            if (data == '#') {
                v[i].push_back(1);
            } else if (data == '.') {
                v[i].push_back(0);
            } else if (data == 'o') {
                totalSheepNum++;
                v[i].push_back(2);
            } else {
                totalWolfNum++;
                v[i].push_back(3);
            }
            visited[i].push_back(false);
        }
    }
    
    int i = 0, j = 0;
    while (1) {
        
        while(1) {
            if (v[i][j] != 1 && visited[i][j] == false) {
                break;
            }
            j++;
            if (j == C) {
                j = 0;
                i++;
            }
            if (i == R) {
                break;
            }
        }
        if (i == R) {
            break;
        }
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        mySet.insert(make_pair(i, j));
        int sheepCount = 0, wolfCount = 0;
        while (!q.empty()) {
            auto s = q.front();
            // 양이라면
            if (v[s.first][s.second] == 2) {
                sheepCount++;
            }
            // 늑대라면
            if (v[s.first][s.second] == 3) {
                wolfCount++;
            }
            visited[s.first][s.second] = true;
            q.pop();
            
            if (chkEastWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                    if (visited[s.first][s.second + 1] == false) {
                        if (v[s.first][s.second + 1] != 1) {
                            q.push(make_pair(s.first, s.second + 1));
                            mySet.insert(make_pair(s.first, s.second + 1));
                        }
                    }
                }
            }
            
            if (chkNorthWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                    if (visited[s.first - 1][s.second] == false) {
                        if (v[s.first - 1][s.second] != 1) {
                            q.push(make_pair(s.first - 1, s.second));
                            mySet.insert(make_pair(s.first - 1, s.second));
                        }
                    }
                }
            }
            
            if (chkWestWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                    if (visited[s.first][s.second - 1] == false) {
                        if (v[s.first][s.second - 1] != 1) {
                            q.push(make_pair(s.first, s.second - 1));
                            mySet.insert(make_pair(s.first, s.second - 1));
                        }
                    }
                }
            }
            
            if (chkSouthWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                    if (visited[s.first + 1][s.second] == false) {
                        if (v[s.first + 1][s.second] != 1) {
                            q.push(make_pair(s.first + 1, s.second));
                            mySet.insert(make_pair(s.first + 1, s.second));
                        }
                    }
                }
            }
        }
        
        if (sheepCount <= wolfCount) {
            totalSheepNum -= sheepCount;
        } else {
            totalWolfNum -= wolfCount;
        }
    }
    
    cout << totalSheepNum << " " << totalWolfNum;
    return 0;
}
