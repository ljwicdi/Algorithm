#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortFunction(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;

		vector<pair<string, int>> rank;
		string name;
		int num;

		for (int j = 0; j < N; ++j) {
			cin >> name >> num;
			rank.push_back({ name, num });
		}

		sort(rank.begin(), rank.end(), sortFunction);
		cout << rank[0].first << '\n';
	}

	return 0;
}