#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool ChkEastWall (int x, int y, int N) { 
    if (y == N - 1) {
        return false;
    } else { 
        return true; 
    } 
    
}

bool ChkNorthWall (int x, int y) {
    if (x == 0) {
        return false; 
    } else { 
        return true; 
    } 
    
}

bool ChkdWestWall (int x, int y) { 
    if (y == 0) { 
        return false; 
    } else { 
        return true; 
    } 
    
}

bool ChkSouthWall (int x, int y, int N) { 
    if (x == N - 1) {
        return false; 
    } else { 
        return true; 
    } 
}

int main() {
    int N; cin >> N;

    vector<int> visited[N]; // false 초기화
    vector<int> house[N];
    int data;
    string str;
    for (int i = 0; i < N; i++) {
        
        cin >> str;
        for (int k = 0; k < str.length(); k++) {
            if (str[k] == '1') {
                house[i].push_back(1);
            } else {
                house[i].push_back(0);
            }
            visited[i].push_back(false);
        }
    }
    
    
    int i = 0, j = 0;

    int cnt = 0;
    vector<int> result;
    set< pair<int, int> > mySet;
    while (1) {
        while (1) {

            if (visited[i][j] == false && house[i][j] == 1) {
                break;
            }

            j++;

            if (j == N) {
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

        int temp = 0;
        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        cnt++;
        
        while (!q.empty()) {
            auto s = q.front();
            
            if(visited[s.first][s.second] == false) {
                temp++;
                
            }
            visited[s.first][s.second] = true;
            q.pop();

            if (ChkEastWall (s.first, s.second, N) && house[s.first][s.second + 1] == 1) {
                if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                    q.push(make_pair(s.first, s.second + 1));
                    mySet.insert(make_pair(s.first, s.second + 1));
                }

            }
            if (ChkNorthWall (s.first, s.second) && house[s.first - 1][s.second] == 1) {
                if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                    q.push(make_pair(s.first - 1, s.second));
                    mySet.insert(make_pair(s.first - 1, s.second));
                }
            }
            
            if (ChkdWestWall (s.first, s.second) && house[s.first][s.second -1] == 1) {
                if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                    q.push(make_pair(s.first, s.second - 1));
                    mySet.insert(make_pair(s.first, s.second - 1));
                }
            }

            if (ChkSouthWall (s.first, s.second, N) && house[s.first + 1][s.second] == 1) {
                if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                    q.push(make_pair(s.first + 1, s.second));
                    mySet.insert(make_pair(s.first + 1, s.second));
                }
            }
        }
        result.push_back(temp);
    }

    



    sort(result.begin(), result.end());
    cout << cnt << "\n";

    for (auto s : result) {
        cout << s << "\n";
    }
    return 0;
}