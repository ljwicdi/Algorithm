#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
struct node {
    int x;
    int y;
    int distance;
};

int row, col;

bool chkNorthWall(int x, int y) {
    if (x == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthWestWall(int x, int y) {
    if (y == 0 || x == 0) {
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

bool chkSouthWestWall(int x, int y) {
    if (x == row - 1 || y == 0) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthWall(int x, int y) {
    if (x == row - 1) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthEastWall(int x, int y) {
    if (x == row - 1 || y == col - 1) {
        return false;
    } else {
        return true;
    }
}

bool chkEastWall(int x, int y) {
    if (y == col - 1) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthEastWall(int x, int y) {
    if (y == col - 1 || x == 0) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    
    cin >> row >> col;
    vector<int> v[row];
    int data;
    queue<node> q;
    set<pair<int, int>> mySet;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> data;
            if (data == 1) {
                node nd;
                nd.x = i;
                nd.y = j;
                nd.distance = 0;
                q.push(nd);
                mySet.insert(make_pair(i, j));
            }
            v[i].push_back(data);
        }
    }
    
    int max = -99999;
    while (!q.empty()) {
        auto s = q.front();
        if (s.distance > max) {
            max = s.distance;
        }
        q.pop();
        
        if (chkNorthWall(s.x, s.y)) {
            if (mySet.find(make_pair(s.x - 1, s.y)) == mySet.end()) {
                if (v[s.x - 1][s.y] != 1) {
                    node nd;
                    nd.x = s.x - 1;
                    nd.y = s.y;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x - 1, s.y));
                }
            }
        }
        
        if (chkNorthWestWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x - 1, s.y - 1)) == mySet.end()) {
                if (v[s.x - 1][s.y - 1] != 1) {
                    node nd;
                    nd.x = s.x - 1;
                    nd.y = s.y - 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x - 1, s.y - 1));
                }
            }
        }
        
        if (chkWestWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x, s.y - 1)) == mySet.end()) {
                if (v[s.x][s.y - 1] != 1) {
                    node nd;
                    nd.x = s.x;
                    nd.y = s.y - 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x, s.y - 1));
                }
            }
        }
        
        if (chkSouthWestWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x + 1, s.y - 1)) == mySet.end()) {
                if (v[s.x + 1][s.y - 1] != 1) {
                    node nd;
                    nd.x = s.x + 1;
                    nd.y = s.y - 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x + 1, s.y - 1));
                }
            }
        }
        
        if (chkSouthWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x + 1, s.y)) == mySet.end()) {
                if (v[s.x + 1][s.y] != 1) {
                    node nd;
                    nd.x = s.x + 1;
                    nd.y = s.y;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x + 1, s.y));
                }
            }
        }
        
        if (chkSouthEastWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x + 1, s.y + 1)) == mySet.end()) {
                if (v[s.x + 1][s.y + 1] != 1) {
                    node nd;
                    nd.x = s.x + 1;
                    nd.y = s.y + 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x + 1, s.y + 1));
                }
            }
        }
        
        if (chkEastWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x, s.y + 1)) == mySet.end()) {
                if (v[s.x][s.y + 1] != 1) {
                    node nd;
                    nd.x = s.x;
                    nd.y = s.y + 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x, s.y + 1));
                }
            }
        }
        
        if (chkNorthEastWall(s.x, s.y)) {
             if (mySet.find(make_pair(s.x - 1, s.y + 1)) == mySet.end()) {
                if (v[s.x - 1][s.y + 1] != 1) {
                    node nd;
                    nd.x = s.x - 1;
                    nd.y = s.y + 1;
                    nd.distance = s.distance + 1;
                    q.push(nd);
                    mySet.insert(make_pair(s.x - 1, s.y + 1));
                }
            }
        }
    }
    
    cout << max;
    
    return 0;
}
