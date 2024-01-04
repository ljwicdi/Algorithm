#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int N, M;

bool chkEastWall(int x, int y) {
    if (y == N - 1) {
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
    if (x == M - 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    
    
    string data;
    cin >> N >> M;
    
    vector<int> v[M];
    vector<bool> visited[M];
    
    // 1 -> 아군, 0 -> 적군
    for (int i = 0; i < M; i++) {
        
            cin >> data;
            
            for (int k = 0; k < data.length(); k++) {
                if (data[k] == 'W') {
                    v[i].push_back(1);
                } else {
                    v[i].push_back(0);
                }
                visited[i].push_back(false);
            }
            
            
        
    }
    
    int i = 0, j = 0;
    int myTeam = 0, enemyTeam = 0;
    int myTeamForce = 0, enemyTeamForce = 0;
    while (1) {
        
        while (1) {
            if (visited[i][j] == false && v[i][j] == 1) {
                myTeam = 1;
                break;
            }
            
            if (visited[i][j] == false && v[i][j] == 0) {
                enemyTeam = 1;
                break;
            }
            
            j++;
            
            if (j == N) {
                j = 0;
                i++;
            }
            
            if (i == M) {
                break;
            }
        }
        
        if (i == M) {
            break;
        }
        
        
        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        set< pair<int, int> > mySet;
        mySet.insert(make_pair(i, j));
        int temp = 0;
        while (!q.empty()) {
            auto s = q.front();
            temp++;
            if (myTeam == 1) {
                visited[s.first][s.second] = true;
                q.pop();
                
                if (chkEastWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        if (visited[s.first][s.second + 1] == false) {
                            if (v[s.first][s.second + 1] == 1) {
                                q.push(make_pair(s.first, s.second + 1));
                                mySet.insert(make_pair(s.first, s.second + 1));
                            }
                        }
                    }
                }
                
                if (chkNorthWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        if (visited[s.first - 1][s.second] == false) {
                            if (v[s.first - 1][s.second] == 1) {
                                q.push(make_pair(s.first - 1, s.second));
                                mySet.insert(make_pair(s.first - 1, s.second));
                            }
                        }
                    }
                }
                
                if (chkWestWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        if (visited[s.first][s.second - 1] == false) {
                            if (v[s.first][s.second - 1] == 1) {
                                q.push(make_pair(s.first, s.second - 1));
                                mySet.insert(make_pair(s.first, s.second - 1));
                            }
                        }
                    }
                }
                
                if (chkSouthWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        if (visited[s.first + 1][s.second] == false) {
                            if (v[s.first + 1][s.second] == 1) {
                                q.push(make_pair(s.first + 1, s.second));
                                mySet.insert(make_pair(s.first + 1, s.second));
                            }
                        }
                    }
                }
            }
            
            else if (enemyTeam == 1) {
                visited[s.first][s.second] = true;
                q.pop();
                
                if (chkEastWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        if (visited[s.first][s.second + 1] == false) {
                            if (v[s.first][s.second + 1] == 0) {
                                q.push(make_pair(s.first, s.second + 1));
                                mySet.insert(make_pair(s.first, s.second + 1));
                            }
                        }
                    }
                }
                
                if (chkNorthWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        if (visited[s.first - 1][s.second] == false) {
                            if (v[s.first - 1][s.second] == 0) {
                                q.push(make_pair(s.first - 1, s.second));
                                mySet.insert(make_pair(s.first - 1, s.second));
                            }
                        }
                    }
                }
                
                if (chkWestWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        if (visited[s.first][s.second - 1] == false) {
                            if (v[s.first][s.second - 1] == 0) {
                                q.push(make_pair(s.first, s.second - 1));
                                mySet.insert(make_pair(s.first, s.second - 1));
                            }
                        }
                    }
                }
                
                if (chkSouthWall(s.first, s.second)) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        if (visited[s.first + 1][s.second] == false) {
                            if (v[s.first + 1][s.second] == 0) {
                                q.push(make_pair(s.first + 1, s.second));
                                mySet.insert(make_pair(s.first + 1, s.second));
                            }
                        }
                    }
                }
            }
        }
        
        if (myTeam == 1) {
            myTeamForce = myTeamForce + temp * temp;
            myTeam = 0;
        } else if (enemyTeam == 1) {
            enemyTeamForce = enemyTeamForce + temp * temp;
            enemyTeam = 0;
        }
    }
    
    cout << myTeamForce << " " << enemyTeamForce;
    return 0;
}
