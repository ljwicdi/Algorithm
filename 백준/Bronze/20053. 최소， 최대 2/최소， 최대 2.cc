#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#define endl '\n'
using namespace std;

//백준 20053번 코드
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt;
		cin >> cnt;

		int max = -1000000;
		int min = 1000000;
		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;
			if (max < num) { max = num; }
			if (min > num) { min = num; }
		}

		cout << min << " " << max << endl;
	}
}
