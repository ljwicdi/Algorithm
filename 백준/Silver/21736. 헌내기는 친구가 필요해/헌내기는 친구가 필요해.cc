
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int N, M;

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
    
    cin >> N >> M;
    vector<char> v[N];
    char data;
    int startX, startY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> data;
            if (data == 'I') {
                startX = i;
                startY = j;
            }
            v[i].push_back(data);
        }
    }
    
    int result = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(startX, startY));
    
    while (!q.empty()) {
        auto s = q.front();
        if (v[s.first][s.second] == 'P') {
            result++;
        }
        q.pop();
        
        if (chkEastWall(s.first, s.second)) {
            if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                if (v[s.first][s.second + 1] != 'X') {
                    q.push(make_pair(s.first, s.second + 1));
                    mySet.insert(make_pair(s.first, s.second + 1));
                }
            }
        }
        
        if (chkNorthWall(s.first, s.second)) {
            if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                if (v[s.first - 1][s.second] != 'X') {
                    q.push(make_pair(s.first - 1, s.second));
                    mySet.insert(make_pair(s.first - 1, s.second));
                }
            }
        }
        
        if (chkWestWall(s.first, s.second)) {
            if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                if (v[s.first][s.second - 1] != 'X') {
                    q.push(make_pair(s.first, s.second - 1));
                    mySet.insert(make_pair(s.first, s.second - 1));
                }
            }
        }
        
        if (chkSouthWall(s.first, s.second)) {
            if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                if (v[s.first + 1][s.second] != 'X') {
                    q.push(make_pair(s.first + 1, s.second));
                    mySet.insert(make_pair(s.first + 1, s.second));
                }
            }
        }
    }
    
    if (result == 0) {
        cout << "TT";
    } else {
        cout << result;
    }
    return 0;
}
