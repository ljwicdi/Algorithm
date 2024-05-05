#include <iostream>
#include <vector>

using namespace std;

int main() {
    int duration, n;
    cin >> n >> duration;

    vector<bool> isExploded(duration + 1, false); // 모든 폭죽이 터지는 순간을 표시하는 배열

    for (int i = 0; i < n; ++i) {
        int period;
        cin >> period;
        
        // period 주기로 폭죽이 터짐을 표시
        for (int j = period; j <= duration; j += period) {
            isExploded[j] = true;
        }
    }

    int count = 0;
    for (bool exploded : isExploded) {
        if (exploded) count++;
    }

    cout << count << endl;

    return 0;
}
