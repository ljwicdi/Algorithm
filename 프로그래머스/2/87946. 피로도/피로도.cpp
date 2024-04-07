#include <string>
#include <vector>
using namespace std;

int dfs(int k, int node, vector<bool> &visited, vector<vector<int>> &dungeons) {
    if (k < dungeons[node][0]) {
        return 0;
    }
    
    visited[node] = true;
    int maxCount = 0;
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i]) {
            int count = dfs(k - dungeons[node][1], i, visited, dungeons);
            maxCount = max(maxCount, count);
        }
    }
    
    visited[node] = false; // Backtrack
    
    return maxCount + 1; // 현재 던전을 방문한 경우도 포함
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visited(dungeons.size(), false);
    
    for (int i = 0; i < dungeons.size(); i++) {
        int count = dfs(k, i, visited, dungeons);
        answer = max(answer, count);
    }
    
    return answer;
}
