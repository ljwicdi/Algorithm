
#include <iostream>
#include <vector>
#include <set>
#include <queue>
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
    
    char data;
    cin >> R >> C;
    vector<int> v[R];
    int totalWolfCnt = 0, totalSheepCnt = 0;
    // 길 : 0, 울타리 : 1, 늑대 : 2, 양 : 3
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> data;
            
            if (data == '.') {
                v[i].push_back(0); 
            } else if(data == '#') {
                v[i].push_back(1);
            } else if(data == 'v') {
                totalWolfCnt++;
                v[i].push_back(2);
            } else {
                totalSheepCnt++;
                v[i].push_back(3);
            }
        }
    }
    
    int i = 0, j = 0;
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(0, 0));
    
    while (1) {
        
        while (1) {
            if (v[i][j] != 1 && mySet.find(make_pair(i, j)) == mySet.end()) {
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
        int wolfCnt = 0, sheepCnt = 0;
        while (!q.empty()) {
            auto s = q.front();
            
            if (v[s.first][s.second] == 2) {
                wolfCnt++;
            } else if (v[s.first][s.second] == 3) {
                sheepCnt++;
            }
            
            q.pop();
            
            if (chkEastWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                    if (v[s.first][s.second + 1] != 1) {
                        q.push(make_pair(s.first, s.second + 1));
                        mySet.insert(make_pair(s.first, s.second + 1));
                    }
                }
            }
            
            if (chkNorthWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                    if (v[s.first - 1][s.second] != 1) {
                        q.push(make_pair(s.first - 1, s.second));
                        mySet.insert(make_pair(s.first - 1, s.second));
                    }
                }
            }
            
            if (chkWestWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                    if (v[s.first][s.second - 1] != 1) {
                        q.push(make_pair(s.first, s.second - 1));
                        mySet.insert(make_pair(s.first, s.second - 1));
                    }
                }
            }
            
            if (chkSouthWall(s.first, s.second)) {
                if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                    if (v[s.first + 1][s.second] != 1) {
                        q.push(make_pair(s.first + 1, s.second));
                        mySet.insert(make_pair(s.first + 1, s.second));
                    }
                }
            }
        }
        
        if (sheepCnt > wolfCnt) {
            // 양이 늑대를 잡아먹음
            totalWolfCnt -= wolfCnt;
        } else {
            totalSheepCnt -= sheepCnt;
        }
    }
    
    cout << totalSheepCnt << " " << totalWolfCnt;
    return 0;
}
