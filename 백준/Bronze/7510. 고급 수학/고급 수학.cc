#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;

	for (int i = 1; i <= t; i++) {
		int a,b,c; cin >> a>> b>> c;
		a *= a;
		b *= b;
		c *= c;

		cout << "Scenario #" << i << ':' << '\n';
		cout << ( (a+b==c || b+c==a || c+a == b ) ? "yes" : "no") << '\n' <<'\n';
	}
}
