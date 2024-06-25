
#include <iostream>
using namespace std;
int main() {
    
    int N, A, B;
    cin >> N;
    cin >> A >> B;
    
    int ableCola = A / 2;
    int ableBear = B;
    int able = ableCola + ableBear;
    
    if (able > N) {
        cout << N;
    } else {
        cout << able;
    }

    return 0;
}