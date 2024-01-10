
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int H, W;

bool chkEastWall(int x, int y) {
    if (y == W - 1) {
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
    if (x == H - 1) {
        return false;
    } else {
        return true;
    }
}

int main() {
    
    int testCase;
    char data;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> H >> W;
        
        vector<int> v[H];
        
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                cin >> data;
                if (data == '#') {
                    v[j].push_back(1);
                } else {
                    v[j].push_back(0);
                }
            }
        }
        
        int j = 0, k = 0;
        set<pair<int, int>> mySet;
        int cnt = 0;
        while (1) {
            while (1) {
                if (v[j][k] == 1 && mySet.find(make_pair(j, k)) == mySet.end()) {
                    break;
                }
                
                k++;
                
                if (k == W) {
                    k = 0;
                    j++;
                }
                
                if (j == H) {
                    break;
                }
            }
            if (j == H) {
                break;
            }
            
            queue<pair<int, int>> q;
            mySet.insert(make_pair(j, k));
            q.push(make_pair(j, k));
            cnt++;
            
            while (!q.empty()) {
                auto s = q.front();
                
                q.pop();
                
                if (chkEastWall(s.first, s.second)) {
                    if (v[s.first][s.second + 1] == 1 && mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        q.push(make_pair(s.first, s.second + 1));
                        mySet.insert(make_pair(s.first, s.second + 1));
                    }
                }
                
                if (chkNorthWall(s.first, s.second)) {
                    if (v[s.first - 1][s.second] == 1 && mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        q.push(make_pair(s.first - 1, s.second));
                        mySet.insert(make_pair(s.first - 1, s.second));
                    }
                }
                
                if (chkWestWall(s.first, s.second)) {
                    if (v[s.first][s.second - 1] == 1 && mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        q.push(make_pair(s.first, s.second - 1));
                        mySet.insert(make_pair(s.first, s.second - 1));
                    }
                }
                
                if (chkSouthWall(s.first, s.second)) {
                    if (v[s.first + 1][s.second] == 1 && mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        q.push(make_pair(s.first + 1, s.second));
                        mySet.insert(make_pair(s.first + 1, s.second));
                    }
                }
            }
            
            
        }
        cout << cnt << "\n";
    }
    return 0;
}
