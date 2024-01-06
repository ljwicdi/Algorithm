
#include <iostream>
#include <vector>
#include <set>
#include <queue>
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

int main()
{
    cin >> N >> M >> K;
    vector<int> v[N];
    vector<bool> visited[N];
    set< pair<int, int> > mySet; 
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            v[i].push_back(0);
            visited[i].push_back(false);
        }
    }
    
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        
        v[x - 1][y - 1] = 1;    // 음식물 쓰레기 위치에 1
    }
    
    int i = 0, j = 0;
    int max = -1;
    while (1) {
        while (1) {
            if (visited[i][j] == false && v[i][j] == 1) {
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
        
        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        mySet.insert(make_pair(i, j));
        int temp = 0;
        while (!q.empty()) {
            auto s = q.front();
            temp++;
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
        
        if (max < temp) {
            max = temp;
        }
    }
    
    cout << max;
    
    return 0;
}
