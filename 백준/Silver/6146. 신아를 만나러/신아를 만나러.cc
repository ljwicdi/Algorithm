
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

bool chkEastWall(int x, int y) {
    if (y == 1000) {
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
    if (x == 1000) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    int X, Y, N, Ai, Bi;
    vector<int> v[1002];
    
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            v[i].push_back(0);
        }
    }
    
    cin >> X >> Y >> N;
    
    // (0, 0) -> (500, 500)
    for (int i = 0; i < N; i++) {
        cin >> Ai >> Bi; // (X, Y)
        
        v[500 - Bi][500 - Ai] = 1;
    }
    
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(500, 500));
    queue<vector<int>> q;
    q.push(vector<int> {500, 500, 0});
    
    int result = 0;
    while (!q.empty()) {
        auto s = q.front();
        if (s[0] == 500 - Y && s[1] == 500 - X) {
            result = s[2];
            break;
        }
        q.pop();
        
        if (chkEastWall(s[0], s[1])) {
            if (v[s[0]][s[1] + 1] == 0) {
                if (mySet.find(make_pair(s[0], s[1] + 1)) == mySet.end()) {
                    q.push(vector<int> {s[0], s[1] + 1, s[2] + 1});
                    mySet.insert(make_pair(s[0], s[1] + 1));
                }
            }
        }
        
        if (chkNorthWall(s[0], s[1])) {
            if (v[s[0] - 1][s[1]] == 0) {
                if (mySet.find(make_pair(s[0] - 1, s[1])) == mySet.end()) {
                    q.push(vector<int> {s[0] - 1, s[1], s[2] + 1});
                    mySet.insert(make_pair(s[0] - 1, s[1]));
                }
            }
        }
        
        if (chkWestWall(s[0], s[1])) {
            if (v[s[0]][s[1] - 1] == 0) {
                if (mySet.find(make_pair(s[0], s[1] - 1)) == mySet.end()) {
                    q.push(vector<int> {s[0], s[1] - 1, s[2] + 1});
                    mySet.insert(make_pair(s[0], s[1] - 1));
                }
            }
        }
        
        if (chkSouthWall(s[0], s[1])) {
            if (v[s[0] + 1][s[1]] == 0) {
                if (mySet.find(make_pair(s[0] + 1, s[1])) == mySet.end()) {
                    q.push(vector<int> {s[0] + 1, s[1], s[2] + 1});
                    mySet.insert(make_pair(s[0] + 1, s[1]));
                }
            }
        }
    }
    
    
    cout << result;
    return 0;
}
