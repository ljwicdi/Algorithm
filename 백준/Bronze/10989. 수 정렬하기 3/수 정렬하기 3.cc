
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N;
    int arr[10001] = {0, };
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        arr[data]++;
    }
    
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
    }
    
    return 0;
}
