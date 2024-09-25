#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1; s2 = s1;
	reverse(s2.begin(), s2.end());

	if (s1 == s2) cout << "true";
	else cout << "false";
}