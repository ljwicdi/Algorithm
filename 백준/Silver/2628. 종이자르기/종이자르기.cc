#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int garo, sero; cin >> sero >> garo;
	vector<int> garocut = { 0,garo };
	vector<int> serocut = { 0,sero };

	int N; cin >> N;
	while (N--) {
		bool x; int y; cin >> x >> y;
		if (x) serocut.push_back(y);
		else garocut.push_back(y);
	}

	sort(garocut.begin(), garocut.end());
	sort(serocut.begin(), serocut.end());

	garo = (int) garocut.size();
	sero = (int) serocut.size();
	
	int maxgaro = 0;
	int maxsero = 0;
	for (int i = 1; i < garo; i++) {
		int temp = garocut[i] - garocut[i - 1];
		if (temp > maxgaro) maxgaro = temp;
	}
	for (int i = 1; i < sero; i++) {
		int temp = serocut[i] - serocut[i - 1];
		if (temp > maxsero) maxsero = temp;
	}

	cout << maxgaro * maxsero;
}