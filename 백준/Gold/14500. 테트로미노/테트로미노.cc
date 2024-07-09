
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int ma;
void solve(vector<vector<int>> & v, int choice) {
    
    int sum;
    if (choice == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M - 3; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i][j + 3];
                
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < N - 3; i++) {
            for (int j = 0; j < M; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 3][j];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 3) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 1][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 4) {
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 2][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 5) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }   
    } else if (choice == 6) {
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 2][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 7) {
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i - 1][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 8) {
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i - 1][j + 1] + v[i - 2][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 9) {
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j] + v[i + 2][j];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 10) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 11) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 12) {
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i + 2][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 13) {
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i - 1][j + 1] + v[i - 1][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 14) {
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i - 1][j] + v[i - 1][j + 1] + v[i - 2][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 15) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i + 1][j + 1] + v[i + 1][j + 2];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 16) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i + 1][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 17) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i - 1][j + 1] + v[i + 1][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 18) {
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M - 2; j++) {
                sum = v[i][j] + v[i][j + 1] + v[i][j + 2] + v[i - 1][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    } else if (choice == 19) {
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < M - 1; j++) {
                sum = v[i][j] + v[i + 1][j] + v[i + 2][j] + v[i + 1][j + 1];
                if (ma < sum) {
                    ma = sum;
                }
            }
        }
    }
    
}

int main() {
    ma = -1;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    
    solve(v, 1);
    solve(v, 2);
    solve(v, 3);
    solve(v, 4);
    solve(v, 5);
    solve(v, 6);
    solve(v, 7);
    solve(v, 8);
    solve(v, 9);
    solve(v, 10);
    solve(v, 11);
    solve(v, 12);
    solve(v, 13);
    solve(v, 14);
    solve(v, 15);
    solve(v, 16);
    solve(v, 17);
    solve(v, 18);
    solve(v, 19);
    cout << ma;
    return 0;
}