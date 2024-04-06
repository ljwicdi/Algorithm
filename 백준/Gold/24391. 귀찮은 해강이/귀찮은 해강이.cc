#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> parent;

int find(int node) {
    if (parent.find(node) == parent.end() || parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        parent[rootA] = rootB;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    vector<int> timeTable(N);
    for (int i = 0; i < N; ++i)
        cin >> timeTable[i];

    int result = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (find(timeTable[i]) != find(timeTable[i + 1])) {
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
