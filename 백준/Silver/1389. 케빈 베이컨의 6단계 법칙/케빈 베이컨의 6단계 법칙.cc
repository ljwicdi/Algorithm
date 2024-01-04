
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first > b.first) {
        return false;
    } else {
        if (a.second < b.second) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    
    // 플로이드 - 와샬 알고리즘
    // 2차원 배열(DP), 거쳐가는 정점이 반복문의 중심 
    
    int N, M;
    cin >> N >> M;
    
    int relation[N + 1][N + 1];
    
    int INF = 1000000000;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                relation[i][j] = 0;
                continue;
            }
            relation[i][j] = INF;
        }
    }
    
    int f1, f2;
    set< pair<int, int> > mySet; // 중복제거
    
    for (int i = 0; i < M; i++) {
        cin >> f1 >> f2;
        
        auto s1 = make_pair(f1, f2);
        auto s2 = make_pair(f2, f1);
        
        // 중복이 없다면 추가함
        if (mySet.find(s1) == mySet.end() && mySet.find(s2) == mySet.end()) {
            relation[f1][f2] = 1;
            relation[f2][f1] = 1;
        }
    }
    
    // 플로이드 - 와샬 알고리즘 
    // k -> 거쳐가는 정점
    for (int k = 1; k < N + 1; k++) {
        // i -> 시작 정점
        for (int i = 1; i < N + 1; i++) {
            // j -> 도착 정점 
            for (int j = 1; j < N + 1; j++) {
                // 업데이트
                if (relation[i][k] + relation[k][j] < relation[i][j]) {
                    relation[i][j] = relation[i][k] + relation[k][j];
                }
            }
        }
    }
    
    
    vector< pair<int, int> > result;
    
    int sum;
    for (int i = 1; i < N + 1; i++) {
        sum = 0;
        
        for (int j = 1; j < N + 1; j++) {
            sum += relation[i][j];
        }
        
        result.push_back(make_pair(sum, i));
       
    }
  
    
    
    sort(result.begin(), result.end(), comp);
    
    cout << result[0].second;
    
    return 0;
}
