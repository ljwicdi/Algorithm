#include <iostream>
#include <vector>
using namespace std;
int goal;

void dfs(vector<vector<bool>> & map, int node, int cnt, vector<int> & result) {
    
    result.push_back(node);
    
    
    if (cnt == goal) {
        for (auto k : result) {
            cout << "a" << k << " ";
        }
        exit(0);
    }
    for (int i = 1; i <= map.size() - 1; i++) {
        if (map[node][i] == true) {
            map[node][i] = false;
            map[i][node] = false;
            cnt++;
            dfs(map, i, cnt, result);
            cnt--;
            result.pop_back();
            map[node][i] = true;
            map[i][node] = true;
        }
    }
}

int main() {
    // matrix로 풀어보기
    int N;
    cin >> N;
    goal = N * (N - 1) / 2;
    
    vector<vector<bool>> map(N + 1, vector<bool>(N + 1, true));
    
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i == j) map[i][j] = false;
        }
    }
    vector<int> result;
    dfs(map, 1, 0, result);

    return 0;
}
