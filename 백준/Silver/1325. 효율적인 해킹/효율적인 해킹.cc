#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> first;
bool visited[10001];
vector<int> v[10001];
 
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) {
        return true;
    } else if (a.first < b.first) {
        return false;
    } else {
        if (a.second < b.second) {
            return true;
        } else {
            return false;
        }
    }
}

int dfs(int node, int current) {
    
    visited[node] = true;
    int currentNum = current;
    for (auto s : v[node]) {
        if (visited[s] == false) {
            currentNum = dfs(s, currentNum + 1);
        }
        
    }
    
    return currentNum;
}

int main()
{

    cin >> N >> M;
   
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    
    
    
    vector< pair<int, int> > result;
    int temp;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N + 1; j++) {
            visited[j] = false;
        }
        temp = dfs(i, 1);
        result.push_back(make_pair(temp, i));
    }
    
    sort(result.begin(), result.end(), comp);
    temp = result[0].first;
    
    for (auto s : result) {
        if (s.first == temp) {
            cout << s.second << " ";
        }
    }
    
    return 0;
}
