#include <iostream>
using namespace std;

int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int a = -10, b = -10;
	while (n--) {
		int x;
		cin >> x;
		if (x > a) a = x;
	}
	while (m--) {
		int x;
		cin >> x;
		if (x > b) b = x;
	}
	cout << a + b;
}