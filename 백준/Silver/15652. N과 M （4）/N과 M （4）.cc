#include <iostream>
#include <vector>
using namespace std;
int N, M;

void solve(int depth, int currentNum, vector<int> v) {
    if (depth == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = currentNum; i <= N; i++) {
        v.push_back(i);
        solve(depth + 1, i, v);
        v.pop_back();
    }
    
}

int main() {
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        vector<int> v;
        v.push_back(i);
        solve(1, i, v);
        v.pop_back();
    }
    
    
    
    return 0;
}