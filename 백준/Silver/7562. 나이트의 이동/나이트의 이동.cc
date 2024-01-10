
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int I;

bool chkEastUp(int x, int y) {
    if (y + 2 >= I || x - 1 < 0) {
        return false;
    } else {
        return true;
    }
}

bool chkEastDown(int x, int y) {
    if (y + 2 >= I || x + 1 >= I) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthRight(int x, int y) {
    if (x + 2 >= I || y + 1 >= I) {
        return false;
    } else {
        return true;
    }
}

bool chkSouthLeft(int x, int y) {
    if (x + 2 >= I || y - 1 < 0) {
        return false;
    } else {
        return true;
    }
}

bool chkWestDown(int x, int y) {
    if (x + 1 >= I || y - 2 < 0) {
        return false;
    } else {
        return true;
    }
}

bool chkWestUp(int x, int y) {
    if (x - 1 < 0 || y - 2 < 0) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthLeft(int x, int y) {
    if (x - 2 < 0 || y - 1 < 0) {
        return false;
    } else {
        return true;
    }
}

bool chkNorthRight(int x, int y) {
    if (x - 2 < 0 || y + 1 >= I) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    int testCase;
    int startX, startY, arriveX, arriveY;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        cin >> I;
        cin >> startX >> startY;
        cin >> arriveX >> arriveY;
        
        set<pair<int, int>> mySet;
        queue<vector<int>> q;
        q.push(vector<int> {startX, startY, 0});
        mySet.insert(make_pair(startX, startY));
        
        int result = 0;
        while (!q.empty()) {
            auto s = q.front();
            if (s[0] == arriveX && s[1] == arriveY) {
                result = s[2];
                break;
            }
            q.pop();
            if (chkEastUp(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] - 1, s[1] + 2)) == mySet.end()) {
                    q.push(vector<int> {s[0] - 1, s[1] + 2, s[2] + 1});
                    mySet.insert(make_pair(s[0] - 1, s[1] + 2));
                }
            }
            
            if (chkEastDown(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] + 1, s[1] + 2)) == mySet.end()) {
                    q.push(vector<int> {s[0] + 1, s[1] + 2, s[2] + 1});
                    mySet.insert(make_pair(s[0] + 1, s[1] + 2));
                }
            }
            
            if (chkSouthRight(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] + 2, s[1] + 1)) == mySet.end()) {
                    q.push(vector<int> {s[0] + 2, s[1] + 1, s[2] + 1});
                    mySet.insert(make_pair(s[0] + 2, s[1] + 1));
                }
            }
            
            if (chkSouthLeft(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] + 2, s[1] - 1)) == mySet.end()) {
                    q.push(vector<int> {s[0] + 2, s[1] - 1, s[2] + 1});
                    mySet.insert(make_pair(s[0] + 2, s[1] - 1));
                }
            }
            
            if (chkWestDown(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] + 1, s[1] - 2)) == mySet.end()) {
                    q.push(vector<int> {s[0] + 1, s[1] - 2, s[2] + 1});
                    mySet.insert(make_pair(s[0] + 1, s[1] - 2));
                }
            }
            
            if (chkWestUp(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] - 1, s[1] - 2)) == mySet.end()) {
                    q.push(vector<int> {s[0] - 1, s[1] - 2, s[2] + 1});
                    mySet.insert(make_pair(s[0] - 1, s[1] - 2));
                }
            }
            
            if (chkNorthLeft(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] - 2, s[1] - 1)) == mySet.end()) {
                    q.push(vector<int> {s[0] - 2, s[1] - 1, s[2] + 1});
                    mySet.insert(make_pair(s[0] - 2, s[1] - 1));
                }
            }
            
            if (chkNorthRight(s[0], s[1])) {
                if (mySet.find(make_pair(s[0] - 2, s[1] + 1)) == mySet.end()) {
                    q.push(vector<int> {s[0] - 2, s[1] + 1, s[2] + 1});
                    mySet.insert(make_pair(s[0] - 2, s[1] + 1));
                }
            }
        }
        cout << result << "\n";
    }

    return 0;
}
