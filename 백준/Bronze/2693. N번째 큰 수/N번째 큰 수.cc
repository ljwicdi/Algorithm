#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A[10];
	int N = 3;
	int num = 0; 
	cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> A[j];
		}
		sort(A, A + 10);
		cout << A[10 - N] << endl;
	}
	return 0;
}