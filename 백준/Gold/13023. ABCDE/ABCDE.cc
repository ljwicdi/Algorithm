#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> v[2000];
int N;

void dfs(int node, set<int> visited, int depth) {
    set<int> visit = visited;

    if (depth >= 4) {
        cout << "1";
        exit(0);
    }

    for (auto s : v[node]) {
        if (visit.find(s) == visit.end()) {
            visit.insert(s);
            dfs(s, visit, depth + 1);
            visit.erase(s);
        }
    }
}

int main() {
    int M;
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        set<int> mySet;
        mySet.insert(i);
        dfs(i, mySet, 0);
    }

    cout << "0";
    return 0;
}
