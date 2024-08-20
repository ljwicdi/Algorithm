#include <iostream>
#include <vector>
using namespace std;

int R, C;

void reverseCycle(vector<vector<int>>& v, int clearX, int clearY) {
    int temp = v[clearX][clearY + 1];
    v[clearX][clearY + 1] = 0;
    clearY++;

    // 오른쪽으로 이동
    for (int j = clearY; j < C - 1; j++) {
        swap(temp, v[clearX][j + 1]);
    }

    // 위로 이동
    for (int i = clearX; i > 0; i--) {
        swap(temp, v[i - 1][C - 1]);
    }

    // 왼쪽으로 이동
    for (int j = C - 1; j > 0; j--) {
        swap(temp, v[0][j - 1]);
    }

    // 아래로 이동
    for (int i = 0; i < clearX - 1; i++) {
        swap(temp, v[i + 1][0]);
    }
}

void cycle(vector<vector<int>>& v, int clearX, int clearY) {
    int temp = v[clearX][clearY + 1];
    v[clearX][clearY + 1] = 0;
    clearY++;

    // 오른쪽으로 이동
    for (int j = clearY; j < C - 1; j++) {
        swap(temp, v[clearX][j + 1]);
    }

    // 아래로 이동
    for (int i = clearX; i < R - 1; i++) {
        swap(temp, v[i + 1][C - 1]);
    }

    // 왼쪽으로 이동
    for (int j = C - 1; j > 0; j--) {
        swap(temp, v[R - 1][j - 1]);
    }

    // 위로 이동
    for (int i = R - 1; i > clearX + 1; i--) {
        swap(temp, v[i - 1][0]);
    }
}

int cal(const vector<vector<int>>& v) {
    int result = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (v[i][j] != -1) {
                result += v[i][j];
            }
        }
    }
    return result;
}

int main() {
    int T, upClearX, upClearY, downClearX, downClearY;
    cin >> R >> C >> T;
    vector<vector<int>> v(R, vector<int>(C));

    bool flag = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> v[i][j];
            if (v[i][j] == -1) {
                if (!flag) {
                    upClearX = i;
                    upClearY = j;
                    flag = true;
                } else {
                    downClearX = i;
                    downClearY = j;
                }
            }
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (T--) {
        vector<vector<int>> temp(R, vector<int>(C, 0));

        // 미세먼지 확산
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (v[i][j] > 0) {
                    int spread_amount = v[i][j] / 5;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C && v[nx][ny] != -1) {
                            temp[nx][ny] += spread_amount;
                            v[i][j] -= spread_amount;
                        }
                    }
                }
            }
        }

        // 원본 맵에 확산 결과 반영
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                v[i][j] += temp[i][j];
            }
        }

        // 공기청정기 작동
        reverseCycle(v, upClearX, upClearY);
        cycle(v, downClearX, downClearY);
    }

    // 미세먼지 계산
    cout << cal(v);

    return 0;
}