
#include <iostream>
using namespace std;
int main() { 
    int N, M;
    cin >> N;
    int price[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }
    
    cin >> M;
    
    int result = 0;
    for (int i = 0; i < M; i++) {
        int wish;
        cin >> wish;
        result += price[wish];
    }
    
    cout << result;

    return 0;
}