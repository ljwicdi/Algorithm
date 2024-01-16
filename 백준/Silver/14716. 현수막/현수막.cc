
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int M, N;
bool chkEastWall(int x, int y) {
    if (y == N - 1) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthEastWall(int x, int y) {
    if (y == N - 1 || x == 0) {
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
    if (x == M - 1 || y == 0) {
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

bool chkSouthEastWall(int x, int y) {
    if (y == N - 1 || x == M - 1) {
        return false;
    } else {
        return true;
    }
}
int main()
{
    int data;
    cin >> M >> N;
    vector<int> v[M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    int result = 0;
    set<pair<int, int>> mySet;
    while(1)
    {
        int i = 0, j = 0;
        while (1) {
            if (v[i][j] == 1 && mySet.find(make_pair(i, j)) == mySet.end()) {
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
        
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        
        mySet.insert(make_pair(i, j));
        result++;
        while(!q.empty()) {
            auto s = q.front();
            q.pop();
            
            if (chkEastWall(s.first, s.second)) {
                if (v[s.first][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first, s.second + 1));
                        q.push(make_pair(s.first, s.second + 1));
                    }
                }
            }
            if (chkNorthEastWall(s.first, s.second)) {
                if (v[s.first - 1][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second + 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first - 1, s.second + 1));
                        q.push(make_pair(s.first - 1, s.second + 1));
                    }
                }
            }
            if (chkNorthWall(s.first, s.second)) {
                if (v[s.first - 1][s.second] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        mySet.insert(make_pair(s.first - 1, s.second));
                        q.push(make_pair(s.first - 1, s.second));
                    }
                }
            }
            if (chkNorthWestWall(s.first, s.second)) {
                if (v[s.first - 1][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first - 1, s.second - 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first - 1, s.second - 1));
                        q.push(make_pair(s.first - 1, s.second - 1));
                    }
                }
            }
            if (chkWestWall(s.first, s.second)) {
                if (v[s.first][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first, s.second - 1));
                        q.push(make_pair(s.first, s.second - 1));
                    }
                }
            }
            if (chkSouthWestWall(s.first, s.second)) {
                if (v[s.first + 1][s.second - 1] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second - 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first + 1, s.second - 1));
                        q.push(make_pair(s.first + 1, s.second - 1));
                    }
                }
            }
            if (chkSouthWall(s.first, s.second)) {
                if (v[s.first + 1][s.second] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        mySet.insert(make_pair(s.first + 1, s.second));
                        q.push(make_pair(s.first + 1, s.second));
                    }
                }
            }
            if (chkSouthEastWall(s.first, s.second)) {
                if (v[s.first + 1][s.second + 1] == 1) {
                    if (mySet.find(make_pair(s.first + 1, s.second + 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first + 1, s.second + 1));
                        q.push(make_pair(s.first + 1, s.second + 1));
                    }
                }
            }
        }
    }
    
    cout << result;
    return 0;
}
