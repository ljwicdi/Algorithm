#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
int N, M, K;

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

int main(void) { 
    cin >> N >> M >> K;

    vector<int> v[N];
    vector<bool> visited[N];
    int data;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> data;
            v[i].push_back(data);
            visited[i].push_back(false);
        }
    }

    
    set<pair<int, int>> mySet;
    int result = 0;
    int i = 0, j = 0;
    while (1) {
        
        while (1) {
            if (visited[i][j] == false) {
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

        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        mySet.insert(make_pair(i, j));
        result++;
        while (!q.empty()) {
            auto s = q.front();
            visited[s.first][s.second] = true;
            q.pop();
            if (chkEastWall(s.first, s.second)) {
                if (abs(v[s.first][s.second + 1] - v[s.first][s.second]) <= K) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first, s.second + 1));
                        q.push(make_pair(s.first, s.second + 1));
                    }
                }
            }

            if (chkNorthWall(s.first, s.second)) {
                if (abs(v[s.first - 1][s.second] - v[s.first][s.second]) <= K) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        mySet.insert(make_pair(s.first - 1, s.second));
                        q.push(make_pair(s.first - 1, s.second));
                    }
                }
            }

            if (chkWestWall(s.first, s.second)) {
                if (abs(v[s.first][s.second - 1] - v[s.first][s.second]) <= K) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        mySet.insert(make_pair(s.first, s.second - 1));
                        q.push(make_pair(s.first, s.second - 1));
                    }
                }
            }

            if (chkSouthWall(s.first, s.second)) {
                if (abs(v[s.first + 1][s.second] - v[s.first][s.second]) <= K) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        mySet.insert(make_pair(s.first + 1, s.second));
                        q.push(make_pair(s.first + 1, s.second));
                    }
                }
            }
        }

    }   
    
    cout << result;

    return 0;
}