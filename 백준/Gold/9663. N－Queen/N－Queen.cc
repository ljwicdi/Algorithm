#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int result = 0;

void dfs(int currentX, vector<bool> &v1, vector<bool> &v2, vector<bool> &v3) {
    if (currentX == N) {
        result++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!v1[i] && !v2[currentX + i] && !v3[currentX - i + N - 1]) {
            v1[i] = true;
            v2[currentX + i] = true;
            v3[currentX - i + N - 1] = true;
            dfs(currentX + 1, v1, v2, v3);
            v1[i] = false;
            v2[currentX + i] = false;
            v3[currentX - i + N - 1] = false;
        }
    }
}

int main() {
    cin >> N;

    vector<bool> v1(N, false);        // 열 검사
    vector<bool> v2(2 * N - 1, false); // 북동-남서 대각선 검사
    vector<bool> v3(2 * N - 1, false); // 북서-남동 대각선 검사

    dfs(0, v1, v2, v3);

    cout << result;
    return 0;
}