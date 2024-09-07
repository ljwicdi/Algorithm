#include <iostream>
using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        ll s = 0, a;
        int n, cnt = 0;
        cin >> n;
        while (n--) {
            cin >> a;
            ll prv = s;
            s += a;
            if (a > 0 && prv > 0 && s < 0) cnt++;
            if (a < 0 && prv < 0 && s > 0) cnt--;
        }
        if (cnt == 0) {
            if (s == 0) cout << 0 << '\n';
            else cout << (s > 0 ? '+' : '-') << '\n';
        }
        else {
            cout << (cnt > 0 ? '+' : '-') << '\n';
        }
    }
}