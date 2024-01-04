
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int M, N, K;

bool chkEastWall(int x, int y) {
    if (y == M - 1) {
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
    if (x == N - 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int testCase, x, y;
    cin >> testCase;
    
    for (int p = 0; p < testCase; p++) {
        cin >> M >> N >> K;
        vector<int> cabbage[N];
        vector<bool> visited[N];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cabbage[j].push_back(0);
                visited[j].push_back(false);
            }
        }
        
        for (int j = 0; j < K; j++) {
            cin >> x >> y;
            
            cabbage[y][x] = 1;
        }
        
        int i = 0, j = 0;
        int cnt = 0;
        while (1) {
            while (1) {
                if (visited[i][j] == false && cabbage[i][j] == 1) {
                    break;
                }
            
                j++;
            
                if (j == M) {
                    j = 0;
                    i++;
                }
            
                if (i == N) {
                    break;
                }
            }
            
            if (i == N) {
                break;
            }
            
            cnt++;
            
            set< pair<int, int> > mySet;
            queue< pair<int, int> > q;
            q.push(make_pair(i, j));
            mySet.insert(make_pair(i, j));
            
            while (!q.empty()) {
                auto s = q.front();
                visited[s.first][s.second] = true;
                q.pop();
                
                if (chkEastWall(s.first, s.second)) {
                    if (visited[s.first][s.second + 1] == false) {
                        if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                            if (cabbage[s.first][s.second + 1] == 1) {
                                q.push(make_pair(s.first, s.second + 1));
                                mySet.insert(make_pair(s.first, s.second + 1));
                            }
                        }
                    }
                }
                
                if (chkNorthWall(s.first, s.second)) {
                    if (visited[s.first - 1][s.second] == false) {
                        if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                            if (cabbage[s.first - 1][s.second] == 1) {
                                q.push(make_pair(s.first - 1, s.second));
                                mySet.insert(make_pair(s.first - 1, s.second));
                            }
                        }
                    }
                }
                
                if (chkWestWall(s.first, s.second)) {
                    if (visited[s.first][s.second - 1] == false) {
                        if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                            if (cabbage[s.first][s.second - 1] == 1) {
                                q.push(make_pair(s.first, s.second - 1));
                                mySet.insert(make_pair(s.first, s.second - 1));
                            }
                        }
                    }
                }
                
                if (chkSouthWall(s.first, s.second)) {
                    if (visited[s.first + 1][s.second] == false) {
                        if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                            if (cabbage[s.first + 1][s.second] == 1) {
                                q.push(make_pair(s.first + 1, s.second));
                                mySet.insert(make_pair(s.first + 1, s.second));
                            }
                        }
                    }
                }
            }
            
        }
        
        cout << cnt << "\n";
        
    }

    return 0;
}
