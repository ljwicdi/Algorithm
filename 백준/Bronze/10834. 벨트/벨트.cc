#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 1;
	int rot = 0;

	int N; cin >> N;
	while (N--) {
		int x, y, r; cin >> x >> y >> r;
		ans /= x;
		ans *= y;
		rot ^= r;
	}

	cout << rot << ' ' << ans;
}