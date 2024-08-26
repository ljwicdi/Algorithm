#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ids[10001];

struct node {
    int a;
    int b;
    int cost;
};

bool comp(node a, node b) {
    if (a.cost < b.cost) {
        return true;
    } else {
        return false;
    }
}

int find(int node) {
   
    while (ids[node] != node) {
        node = ids[node];
    }
   
    return node;
}

void uni(int a, int b) {
   
    int rootA = find(a);
    int rootB = find(b);
   
    if (rootA < rootB) {
        ids[rootB] = rootA;    
    } else {
        ids[rootA] = rootB;
    }

}

int main() {
   
    // 크루스칼 알고리즘
    // 그리디
    // 간선을 오름차순으로 정렬한다
    // 가중치가 작은 간선을 하나씩 선택한다.
    // 선택한 간선에 연결되어있는 두개의 노드로 싸이클 여부를 판별한다.
    // 두개의 노드가 같은 집합에 있으면
    // 이 간선을 선택할 시 사이클이 형성되는 것이다.
   
    int V, E;
    cin >> V >> E;
   
    for (int i = 0; i < 10001; i++) {
        ids[i] = i;
    }
   
    vector<node> graph;
    for (int i = 0; i < E; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph.push_back({a, b, cost});
       
    }
   
    sort(graph.begin(), graph.end(), comp);
   
    int result = 0, edgeCnt = 0;
    for (int i = 0; i < graph.size(); i++) {
       
        if (find(graph[i].a) == find(graph[i].b)) {
            continue;
        }
       
        uni(graph[i].a, graph[i].b);
        result += graph[i].cost;
       
        edgeCnt++;
       
        if (edgeCnt == V - 1) {
            break;
        }
    }
   
    cout << result;
    return 0;
}