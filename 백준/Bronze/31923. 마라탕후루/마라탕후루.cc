
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, P, Q;
    cin >> N >> P >> Q;
    
    int cnt[N + 1] = {0, };
    vector<int> A(N + 1);
    vector<int> B(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    
    bool isSame = false;
    string result = "YES";
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 10000; j++) {
            if (A[i] == B[i]) {
                isSame = true;
                break;
            }
            
            A[i] += P;
            B[i] += Q;
            cnt[i]++;
        }
        
        if (!isSame) {
            result = "NO";
        }
        isSame = false;
    }
    
    if (result == "YES") {
        cout << result << "\n";
        for (int i = 1; i <= N; i++) {
            cout << cnt[i] << " ";
        }
    } else {
        cout << result;
    }

    return 0;
}