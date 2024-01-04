#include <iostream>

using namespace std;

int main()
{
    // 2 - 친구 ?
    
    int N;
    char data;
    cin >> N;
    
    int friends[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> data;
            
            if (data == 'Y') {
                friends[i][j] = 1;
            } else {
                friends[i][j] = 0;
            }
        }
    }
    
    int max = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                if (friends[i][j] == 1) {
                    cnt++;
                } else {
                    for (int k = 0; k < N; k++) {
                        if (friends[i][k] == 1) {
                            if (friends[j][k] == 1) {
                                cnt++;
                                break;
                            }
                        }
                    }
                }
                
            }
            
            
        }
        
        if (max < cnt) {
            max = cnt;
        }
    }
    
    cout << max;

    return 0;
}
