
#include <iostream>
using namespace std;
int tShirt = 0;

void solve(int size, int T) {
    if (size % T == 0) {
        tShirt += (size / T);
    } else {
        tShirt += (size / T) + 1;
    }
}
int main() {
    
    int N;
    cin >> N;
    int S, M, L, XL, XXL, XXXL;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    int T, P;
    cin >> T >> P;
    
    solve(S, T);
    solve(M, T);
    solve(L, T);
    solve(XL, T);
    solve(XXL, T);
    solve(XXXL, T);

    cout << tShirt << "\n";
    cout << N / P << " " << N % P;
    return 0;
}
