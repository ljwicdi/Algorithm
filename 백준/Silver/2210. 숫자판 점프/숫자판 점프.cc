
#include <iostream>
#include <queue>
#include <set>
using namespace std;

bool chkEastWall(int x, int y) {
    if (y == 4) {
        return false;
    } else {
        return true;
    }
}

bool chkNortWall(int x, int y) {
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
    if (x == 4) {
        return false;
    } else {
        return true;
    }
}

int main() {
    
    set<string> mySet;
    int data;
    vector<int> digit[5];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> data;
            digit[i].push_back(data);
        }
    }
    
    int i = 0, j = 0;
    while (1) {
        
        queue< pair<vector<int>, string> > q;
        q.push( make_pair(vector<int> {i, j}, to_string(digit[i][j])));
        
        while(!q.empty()) {
            auto s = q.front();
            
            if (s.second.length() == 6) {
                if (mySet.find(s.second) == mySet.end()) {
                    mySet.insert(s.second);
                }
                q.pop();
                continue;
            }
          
            
            q.pop();
            
            string temp;
            if (chkEastWall(s.first[0], s.first[1])) {
                q.push(make_pair(vector<int> {s.first[0], s.first[1] + 1}, s.second + to_string(digit[s.first[0]][s.first[1] + 1])));
            }
            
            if (chkNortWall(s.first[0], s.first[1])) {
                q.push(make_pair(vector<int> {s.first[0] - 1, s.first[1]}, s.second + to_string(digit[s.first[0] - 1][s.first[1]])));
            }
            
            if (chkWestWall(s.first[0], s.first[1])) {
                q.push(make_pair(vector<int> {s.first[0], s.first[1] - 1}, s.second + to_string(digit[s.first[0]][s.first[1] - 1])));
            }
            
            if (chkSouthWall(s.first[0], s.first[1])) {
                q.push(make_pair(vector<int> {s.first[0] + 1, s.first[1]}, s.second + to_string(digit[s.first[0] + 1][s.first[1]])));
            }
        }
        
        j++;
        
        if (j == 5) {
            j = 0;
            i++;
        }
        
        if (i == 5) {
            break;
        }
        
    }
    
    cout << mySet.size();
    return 0;
}
