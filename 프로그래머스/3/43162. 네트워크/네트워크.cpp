#include <string>
#include <vector>
#include <set>
using namespace std;
// 집합의 원소 개수 (루트 노드 기준임)
int sizes[200];
int parent[200];

// 본인의 제일 멀리 있는 조상을 찾아줌 (root)
int root(int i) {
    int temp = i;
    while (i != parent[i]) {
        i = parent[i];
    }   
    
    return i;
}

// 같은 집합에 속하는 지 체크 
bool find(int i, int j) {
    if (root(i) == root(j)) {
        return true;
    } else {
        return false;
    }
}

// 같은 집합에 포함 시켜줌 
void uni(int i, int j) {
    // 작은집합이 큰집합 밑에 달려야함 
    if (sizes[root(i)] <= sizes[root(j)]) {
        sizes[root(j)] = sizes[root(j)] + sizes[root(i)];
        parent[root(i)] = root(j);
    } else {
        sizes[root(i)] = sizes[root(i)] + sizes[root(j)];
        parent[root(j)] = root(i);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    // union-find로 풀어보자 
    
    
    // 본인의 부모가 담긴 배열 
    int data;
    // 초기에는 본인 자신은 본인이 부모임 
    for (int i = 0; i < 200; i++) {
        parent[i] = i;
        sizes[i] = 0;
    }
    
    // 연결을 해주자
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            // 연결되어야한다면 
            if (computers[i][j] == 1) {
                // 연결되어야하는데 아직 연결된 상태가 아니라면
                if (find(i, j) == false) {
                    // 연결 해줌 
                    uni(i, j);
                }
            }
        }
    }
    set<int> s;
    for (int i = 0; i < computers.size(); i++) {
        s.insert(root(i));
    }
    
    return s.size();
}