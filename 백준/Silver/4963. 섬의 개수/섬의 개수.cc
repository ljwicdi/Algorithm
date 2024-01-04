
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

bool ChkEastWall(int x, int y, int w) {
    if (y == w - 1) {
        return false;
    } else {
        return true;
    }
}

bool ChkNorthWall(int x, int y) {
    if (x == 0) {
        return false;
    } else {
        return true;
    }
}

bool ChkWestWall(int x, int y) {
    if (y == 0) {
        return false;
    } else {
        return true;
    }
}

bool ChkSouthWall(int x, int y, int h) {
    if (x == h - 1) {
        return false;
    } else {
        return true;
    }
}

bool ChkNorthLeftWall(int x, int y) {
    if (x == 0 || y == 0) {
        return false;
    } else {
        return true;
    }
}

bool ChkNortRightWall(int x, int y, int w) {
    if (x == 0 || y == w - 1) {
        return false;
    } else {
        return true;
    }
}

bool ChkSouthLeftWall(int x, int y, int h) {
    if (y == 0 || x == h - 1) {
        return false;
    } else {
        return true;
    }
}

bool ChkSouthRightWall(int x, int y, int w, int h) {
    if (x == h - 1 || y == w - 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    
    
    int w, h, data, i, j, cnt;
    
    
    while (1) {
        
        cin >> w >> h;
        vector<int> island[h];
        vector<bool> visited[h];
        cnt = 0;    // 섬의 개수 카운팅
        
        if (w == 0 && h == 0) {
            break;
        }
        
        // 섬 정보 입력
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> data;
                if (data == 1) {
                     island[i].push_back(1);
                } else {
                    island[i].push_back(0);
                }
                visited[i].push_back(false);
            }   
        }
        
        i = 0, j = 0;
       
        while (1) {
            while (1) {
            
                if (visited[i][j] == false && island[i][j] == 1) {
                    break;
                }
            
                j++;
            
                if (j == w) {
                    j = 0;
                    i++;
                }
            
                if (i == h) {
                    break;
                }
            
            }
        
            if (i == h) {
                cout << cnt << "\n";
                break;
            }
        
            set< pair<int, int> > mySet;
        
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            mySet.insert(make_pair(i, j));
            cnt++;
            while (!q.empty()) {
                
                auto s = q.front();
                visited[s.first][s.second] = true;
                q.pop();
            
                if (ChkEastWall(s.first, s.second, w) && visited[s.first][s.second + 1] == false && island[s.first][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        q.push(make_pair(s.first, s.second + 1));
                        mySet.insert(make_pair(s.first, s.second + 1));
                    }
                }
            
                if (ChkNorthWall(s.first, s.second) && visited[s.first - 1][s.second] == false && island[s.first - 1][s.second] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        q.push(make_pair(s.first - 1, s.second));
                        mySet.insert(make_pair(s.first - 1, s.second));
                    }
                }
            
                if (ChkWestWall(s.first, s.second) && visited[s.first][s.second - 1] == false && island[s.first][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        q.push(make_pair(s.first, s.second - 1));
                        mySet.insert(make_pair(s.first, s.second - 1));
                    }
                }
            
                if (ChkSouthWall(s.first, s.second, h) && visited[s.first + 1][s.second] == false && island[s.first + 1][s.second] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        q.push(make_pair(s.first + 1, s.second));
                        mySet.insert(make_pair(s.first + 1, s.second));
                    }
                }
            
                if (ChkNorthLeftWall(s.first, s.second) && visited[s.first - 1][s.second - 1] == false && island[s.first - 1][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second - 1)) == mySet.end()) {
                        q.push(make_pair(s.first - 1, s.second - 1));
                        mySet.insert(make_pair(s.first - 1, s.second - 1));
                    }
                }
            
                if (ChkNortRightWall(s.first, s.second, w) && visited[s.first - 1][s.second + 1] == false && island[s.first - 1][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second + 1)) == mySet.end()) {
                        q.push(make_pair(s.first - 1, s.second + 1));
                        mySet.insert(make_pair(s.first - 1, s.second + 1));
                    }
                }
            
                if (ChkSouthLeftWall(s.first, s.second, h) && visited[s.first + 1][s.second - 1] == false && island[s.first + 1][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second - 1)) == mySet.end()) {
                        q.push(make_pair(s.first + 1, s.second - 1));
                        mySet.insert(make_pair(s.first + 1, s.second - 1));
                    }
                }
            
                if (ChkSouthRightWall(s.first, s.second, w, h) && visited[s.first + 1][s.second + 1] == false && island[s.first + 1][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second + 1)) == mySet.end()) {
                        q.push(make_pair(s.first + 1, s.second + 1));
                        mySet.insert(make_pair(s.first + 1, s.second + 1));
                    }
                }
            }
        } 
    }
    return 0;
}
