
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int N;
    cin >> N;
    vector<int> score(N);
    
    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }
    
    sort(score.begin(), score.end());
    
    cout << score[N - 1] - score[0];

    return 0;
}
