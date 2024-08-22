#include <iostream>
#include <vector>
using namespace std;
int N;
int result = 0;
void dfs(vector<vector<int>> & v, pair<int, int> a, pair<int, int> b, int state) {
   
    // 현재의 상태 -> 1 : 가로, 2 : 세로, 3 : 대각
    if (b.first == N - 1 && b.second == N - 1) {
        result++;
        return;
    }
   
    if (state == 1) {
        // 가로
       
        // 옆으로 밀기
        if (b.second + 1 < N && v[b.first][b.second + 1] != 1) {
            dfs(v, make_pair(a.first, a.second + 1), make_pair(b.first, b.second + 1), 1);
        }
        // 대각으로 밀기
        if (b.second + 1 < N && b.first + 1 < N && v[b.first][b.second + 1] != 1 && v[b.first + 1][b.second + 1] != 1 && v[b.first + 1][b.second]!= 1) {
            dfs(v, make_pair(a.first, a.second + 1), make_pair(b.first + 1, b.second + 1), 3);
        }
    } else if (state == 2) {
        // 세로
       
        // 밑으로 밀기
        if (b.first + 1 < N && v[b.first + 1][b.second] != 1) {
            dfs(v, make_pair(a.first + 1, a.second), make_pair(b.first + 1, b.second), 2);
        }
        // 대각으로 밀기
        if (b.second + 1 < N && b.first + 1 < N && v[b.first][b.second + 1] != 1 && v[b.first + 1][b.second + 1] != 1 && v[b.first + 1][b.second]!= 1) {
            dfs(v, make_pair(a.first + 1, a.second), make_pair(b.first + 1, b.second + 1), 3);
        }
   
    } else if (state == 3) {
        // 대각
       
        // 옆으로밀기
        if (b.second + 1 < N && v[b.first][b.second + 1] != 1) {
            dfs(v, make_pair(a.first, a.second + 1), make_pair(b.first, b.second + 1), 1);
        }
        // 밑으로 밀기
        if (b.first + 1 < N && v[b.first + 1][b.second] != 1) {
            dfs(v, make_pair(a.first + 1, a.second), make_pair(b.first + 1, b.second), 2);
        }
        // 대각으로 밀기
        if (b.second + 1 < N && b.first + 1 < N && v[b.first][b.second + 1] != 1 && v[b.first + 1][b.second + 1] != 1 && v[b.first + 1][b.second]!= 1) {
            dfs(v, make_pair(a.first + 1, a.second + 1), make_pair(b.first + 1, b.second + 1), 3);
        }
    }
}
int main() {
   
    cin >> N;
    vector<vector<int>> v(N);
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int data;
            cin >> data;
            v[i].push_back(data);
        }
    }
   
    // dfs
    int state = 1;
    dfs(v, make_pair(0, 0), make_pair(0, 1), state);
   
    cout << result;
    return 0;
}