
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    char data;
    cin >> N >> M;
    vector<char> v[N];
    
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> data;
            v[i].push_back(data);
        }
    }
    
    int garo = 0;
    int first = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '-') {
                if (first == 1) {
                    garo++;
                    first = 0; 
                }
            } else {
                first = 1;
            }
        }
        first = 1;
    }
    
    int sero = 0;
    first = 1;
    for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (v[j][i] == '|') {
                if (first == 1) {
                    sero++;
                    first = 0;
                }
            } else {
                first = 1;
            }
        }
        first = 1;
    }
    
    cout << garo + sero;
    

    return 0;
}
