#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

struct node {
    int distance;
    vector<vector<char>> map;
};

int cal(vector<vector<char>>& map) {
    int result = 0;
    int first = 8;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == '*') {
                result = result + pow(2, first);
                
            } 
            first--;
        }
    }
    return result;
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        int goal = 0;
        int first = 8; 
        vector<vector<char>> map(3, vector<char>(3, '-'));
        
        // 입력 보드 받기
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cin >> map[j][k];
                if (map[j][k] == '*') {
                    goal = goal + pow(2, first);
                    first--;
                } else {
                    first--;
                }
            }
        }


        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int result = 9999;
        
        
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                set<int> mySet; // 중복체크
                mySet.insert(0);
                queue<node> q;
                node nd;
                nd.distance = 0;
                vector<vector<char>> temp(3, vector<char>(3, '.'));
                nd.map = temp;
                q.push(nd);
                
                int d = 999;
                
                while (!q.empty()) {
                    auto s = q.front();
                    
                    if (cal(s.map) == goal) {
                        d = s.distance;
                        break;
                    }
                    q.pop();
                    
                    
                    //모든 곳 다 클릭
                    for (int z = 0; z  < 3; z++) {
                        for (int x = 0; x < 3; x ++) {
                            vector<vector<char>> next = s.map;
                           
                            
                            if (next[z][x] == '*') {
                                next[z][x] = '.';
                            } else {
                                next[z][x] = '*';
                            }
                            
                            for (int l = 0; l < 4; l++) {
                                int nx = z + dx[l];
                                int ny = x + dy[l];
                                
                                if (nx < 0 || ny < 0 || nx == 3 || ny == 3) {
                                    continue;
                                }
                                
                                if (next[nx][ny] == '*') {
                                    next[nx][ny] = '.';
                                } else {
                                    next[nx][ny] = '*';
                                }
                            }
                            
                            
                            if (mySet.find(cal(next)) == mySet.end()) {
                                mySet.insert(cal(next));
                                node nd;
                                nd.distance = s.distance + 1;
                                nd.map = next;
                                q.push(nd);
                            }
                        }
                            
                    }
                }
                    
                if (d < result) {
                    result = d;
            }
               
        } 
                
        
        
        }
        cout << result << "\n";
    }
   
    return 0;
}
