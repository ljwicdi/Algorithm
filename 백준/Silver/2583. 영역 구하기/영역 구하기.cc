
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool chkEastWall(int x, int y, int N) {
    if (y == N - 1) {
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

bool chkSouthWall(int x, int y, int M) {
    if (x == M - 1) {
        return false;
    } else {
        return true;
    }
}

int main()
{
    /*
        사각형에 포함되는 영역을 0으로 초기화, 나머지는 1로 초기화 
        1인 부분을 그래프 탐색 (그림, 섬의 개수 구하기랑 동일함)
        그림을 반대로 뒤집었다고 생각
    */
    
    
    
    int M, N, K;
    
    cin >> M >> N >> K;
    
    vector<int> graphPaper[M];
    vector<bool> visited[M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            graphPaper[i].push_back(1);
            visited[i].push_back(false);
        }
    }
    
    int x1, y1, x2, y2;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                graphPaper[j][k] = 0;
            }
        }
    }
    
    
    
    int i = 0, j = 0;
   
    vector<int> result;
    int cnt = 0;
    while (1) {
        
        while (1) {
            if (visited[i][j] == false && graphPaper[i][j] == 1) {
                break;
            }
            
            j++;
            
            if (j == N) {
                j = 0;
                i++;
            }
            
            if (i == M) {
                break;
            }
        }
        
        if (i == M) {
            break;
        }
        
        queue< pair<int, int> > q;
        q.push(make_pair(i, j));
        set< pair<int, int> > mySet;
        mySet.insert(make_pair(i, j));
        cnt++;
        int temp = 0;
        while (!q.empty()) {
            auto s = q.front();
            visited[s.first][s.second] = true;
            q.pop();
            temp++;
            
            if (chkEastWall(s.first, s.second, N) && visited[s.first][s.second + 1] == false && graphPaper[s.first][s.second + 1] == 1) {
                if (mySet.find(make_pair(s.first, s.second + 1)) == mySet.end()) {
                    q.push(make_pair(s.first, s.second + 1));
                    mySet.insert(make_pair(s.first, s.second + 1));
                }
            }
            
            if (chkNorthWall(s.first, s.second) && visited[s.first - 1][s.second] == false && graphPaper[s.first - 1][s.second] == 1) {
                if (mySet.find(make_pair(s.first - 1, s.second)) == mySet.end()) {
                    q.push(make_pair(s.first - 1, s.second));
                    mySet.insert(make_pair(s.first - 1, s.second));
                }
            }
            
            if (chkWestWall(s.first, s.second) && visited[s.first][s.second - 1] == false && graphPaper[s.first][s.second - 1] == 1) {
                if (mySet.find(make_pair(s.first, s.second - 1)) == mySet.end()) {
                    q.push(make_pair(s.first, s.second - 1));
                    mySet.insert(make_pair(s.first, s.second - 1));
                }
            }
            
            if (chkSouthWall(s.first, s.second, M) && visited[s.first + 1][s.second] == false && graphPaper[s.first + 1][s.second] == 1) {
                if (mySet.find(make_pair(s.first + 1, s.second)) == mySet.end()) {
                    q.push(make_pair(s.first + 1, s.second));
                    mySet.insert(make_pair(s.first + 1, s.second));
                }
            }
        }
        
        result.push_back(temp);
    }
    
    cout << cnt << "\n";
    sort(result.begin(), result.end());
    
    for(auto s : result) {
        cout << s << " ";
    }
    
    return 0;
}
