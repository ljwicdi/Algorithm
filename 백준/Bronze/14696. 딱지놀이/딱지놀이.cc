#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N;

char solution() {
	map<int, int> list;
	int a, b;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int n; cin >> n;
		list[n]++;
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		int n; cin >> n;
		list[n]--;
	}
	for (int i = 4; i > 0; i--) {
		if (list[i] == 0) {
			continue;
		}
		return list[i] > 0 ? 'A' : 'B';
	}
	return 'D';

}

int main() {
	cin >> N;
	for (int k = 0; k < N; k++) {
		cout << solution() << endl;
	}
	return 0;
}