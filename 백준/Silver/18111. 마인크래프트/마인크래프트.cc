
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    // 땅을 고르게 만들기
    // 높이 쌓아올려야함 (블록이 인벤토리에 존재하면 최대한 쌓기 <쌓는 것은 시간이 덜 걸린다>)
    int N, M, B;
    cin >> N >> M >> B;
    int t = 0, mi = 99999999, ma = -1;
    vector<vector<int>> v(N, vector<int> (M, 0)); 
    map<int, int> myMap;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
            myMap[v[i][j]]++;
            if (mi > v[i][j]) {
                mi = v[i][j];
            }
            
            if (ma < v[i][j]) {
                ma = v[i][j];
            }
        }
    }
    
    while (1) {
        if (mi == ma) {
            break;
        }
        
        if (ma - mi > 1) {
            if (myMap[mi] <= B) {
                if (2 * myMap[ma] > myMap[mi]) {
                    myMap[mi + 1] += myMap[mi];
                    B = B - myMap[mi];
                    t += myMap[mi];
                    myMap[mi] = 0;
                    mi++;
                } else if (2 * myMap[ma] < myMap[mi]) {
                    myMap[ma - 1] += myMap[ma];
                    B = B + myMap[ma];
                    t += 2 * myMap[ma];
                    myMap[ma] = 0;
                    ma--;
                } else {
                    myMap[mi + 1] += myMap[mi];
                    B = B - myMap[mi];
                    t += myMap[mi];
                    myMap[mi] = 0;
                    mi++;
                }
                
            } else {
                myMap[ma - 1] += myMap[ma];
                B = B + myMap[ma];
                t += 2 * myMap[ma];
                myMap[ma] = 0;
                ma--;
            } 
        } else {
            if (myMap[mi] <= B) {
                if (2 * myMap[ma] > myMap[mi]) {
                    myMap[mi + 1] += myMap[mi];
                    B = B - myMap[mi];
                    t += myMap[mi];
                    myMap[mi] = 0;
                    mi++;
                } else if (2 * myMap[ma] < myMap[mi]) {
                    myMap[ma - 1] += myMap[ma];
                    B = B + myMap[ma];
                    t += 2 * myMap[ma];
                    myMap[ma] = 0;
                    ma--;
                } else {
                    myMap[mi + 1] += myMap[mi];
                    B = B - myMap[mi];
                    t += myMap[mi];
                    myMap[mi] = 0;
                    mi++;
                }
                
            } else {
                myMap[ma - 1] += myMap[ma];
                B = B + myMap[ma];
                t += 2 * myMap[ma];
                myMap[ma] = 0;
                ma--;
            }
        }
        
        
        
    }
    
    cout << t << " " << ma;
    return 0;
}