#include <iostream>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3, rx, ry;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	rx = x1;
	ry = y1;
	if (rx == x2)
		rx = x3;
	else if (rx == x3)
		rx = x2;
	
	if (ry == y2)
		ry = y3;
	else if (ry == y3)
		ry = y2;

	cout << rx << " " << ry << "\n";
}