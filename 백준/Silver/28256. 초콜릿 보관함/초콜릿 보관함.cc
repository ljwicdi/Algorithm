
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    
    for (int o = 0; o < testCase; o++) {
        
        vector<char> v[3];
        vector<bool> visited[3];
        vector<int> result;
        vector<int> comp;
        char data;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> data;
                v[j].push_back(data);
                visited[j].push_back(false);
            }
        }
        int n;
        int num;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> num;
            comp.push_back(num);
        }
        int i = 0, j = 0;
        
        while (1) {
            
            while (1) {
                if (visited[i][j] == false && v[i][j] == 'O') {
                    break;
                }
                
                j++;
                
                if (j == 3) {
                    j = 0;
                    i++;
                }
                
                if (i == 3) {
                    break;
                }
            }
            
            if (i == 3) {
                break;
            }
            
            queue<pair<int, int>> q;
            set<pair<int, int>> mySet;
            mySet.insert(make_pair(i, j));
            q.push(make_pair(i, j));
            int cnt = 0;
            while (!q.empty()) {
                auto s = q.front();
                visited[s.first][s.second] = true;
                cnt++;
                q.pop();
                
                if (s.second < 2) {
                    if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                        if (v[s.first][s.second + 1] == 'O') {
                            q.push(make_pair(s.first, s.second + 1));
                            mySet.insert(make_pair(s.first, s.second + 1));
                        }
                    }
                }
                
                if (s.first > 0) {
                    if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                        if (v[s.first - 1][s.second] == 'O') {
                            q.push(make_pair(s.first - 1, s.second));
                            mySet.insert(make_pair(s.first - 1, s.second));
                        }
                    }
                }
                
                if (s.second > 0) {
                    if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                        if (v[s.first][s.second - 1] == 'O') {
                            q.push(make_pair(s.first, s.second - 1));
                            mySet.insert(make_pair(s.first, s.second - 1));
                        }
                    }
                }
                
                if (s.first < 2) {
                    if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                        if (v[s.first + 1][s.second] == 'O') {
                            q.push(make_pair(s.first + 1, s.second));
                            mySet.insert(make_pair(s.first + 1, s.second));
                        }
                    }
                }
                
            }
            
            result.push_back(cnt);
        }
        
        sort(result.begin(), result.end());
        
        if (result.size() != comp.size()) {
            cout << "0\n";
        } else {
            int out = 1;
            for (int p = 0; p < n; p++) {
                if (comp[p] != result[p]) {
                    out = 0;
                    break;
                }
            }
            cout << out << "\n";
        }
        
       
    }

    return 0;
}
