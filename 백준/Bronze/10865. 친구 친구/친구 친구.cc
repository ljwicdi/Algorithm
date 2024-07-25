#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int outDegree[N + 1] = {0, };
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        outDegree[a]++;
        outDegree[b]++;
    }
    
    for (int i = 1; i <= N; i++) {
        cout << outDegree[i] << "\n";
    }
    
}