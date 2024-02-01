#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int N;
struct node {
    int x;
    int y;
    int distance;
};

bool chkOne(int x, int y) {
    if (x - 2 >= 0 && y - 1 >= 0) {
        return true;
    } else {
        return false;
    }
}

bool chkTwo(int x, int y) {
    if (x - 2 >= 0 && y + 1 <= N - 1) {
        return true;
    } else {
        return false;
    }
}

bool chkThree(int x, int y) {
    if (y - 2 >= 0) {
        return true;
    } else {
        return false;
    }
}

bool chkFour(int x, int y) {
    if (y + 2 <= N - 1) {
        return true;
    } else {
        return false;
    }
}

bool chkFive(int x, int y) {
    if (x + 2 <= N - 1 && y - 1 >= 0) {
        return true;
    } else {
        return false;
    }
}

bool chkSix(int x, int y) {
    if (x + 2 <= N - 1 && y + 1 <= N - 1) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    
    cin >> N;
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    queue<node> q;
    
    node nd;
    nd.x = r1;
    nd.y = c1;
    nd.distance = 0;
    q.push(nd);
    set<pair<int, int>> mySet;
    mySet.insert(make_pair(r1, c1));
    
    int result = -1;
    while (!q.empty()) {
        auto s = q.front();
        
        if (s.x == r2 && s.y == c2) {
            result = s.distance;
            break;
        }
        
        q.pop();
        
        if (chkOne(s.x, s.y)) {
            if (mySet.find(make_pair(s.x - 2, s.y - 1)) == mySet.end()) {
                mySet.insert(make_pair(s.x - 2, s.y - 1));
                node nd;
                nd.x = s.x - 2;
                nd.y = s.y - 1;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        if (chkTwo(s.x, s.y)) {
            if (mySet.find(make_pair(s.x - 2, s.y + 1)) == mySet.end()) {
                mySet.insert(make_pair(s.x - 2, s.y + 1));
                node nd;
                nd.x = s.x - 2;
                nd.y = s.y + 1;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        if (chkThree(s.x, s.y)) {
            if (mySet.find(make_pair(s.x, s.y - 2)) == mySet.end()) {
                mySet.insert(make_pair(s.x, s.y - 2));
                node nd;
                nd.x = s.x;
                nd.y = s.y - 2;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        if (chkFour(s.x, s.y)) {
            if (mySet.find(make_pair(s.x, s.y + 2)) == mySet.end()) {
                mySet.insert(make_pair(s.x, s.y + 2));
                node nd;
                nd.x = s.x;
                nd.y = s.y + 2;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        if (chkFive(s.x, s.y)) {
            if (mySet.find(make_pair(s.x + 2, s.y - 1)) == mySet.end()) {
                mySet.insert(make_pair(s.x + 2, s.y - 1));
                node nd;
                nd.x = s.x + 2;
                nd.y = s.y - 1;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
        
        if (chkSix(s.x, s.y)) {
            if (mySet.find(make_pair(s.x + 2, s.y + 1)) == mySet.end()) {
                mySet.insert(make_pair(s.x + 2, s.y + 1));
                node nd;
                nd.x = s.x + 2;
                nd.y = s.y + 1;
                nd.distance = s.distance + 1;
                q.push(nd);
            }
        }
    }
    
    cout << result;
    
    return 0;
}
