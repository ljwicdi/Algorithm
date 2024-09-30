#include <iostream>
#include <algorithm>
using namespace std;
int maxNum(int a, int b) { //최대공약수 구하는 함수
	int n = min(a, b);
	int result;
	for (int i = 1; i <= n; i++) {
		if (a % i == 0 && b % i == 0)
			result = i;
	}
	return result;
}
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		int a, b, max;
		scanf("%d %d", &a, &b);
		max = maxNum(a, b); //최대공약수
		cout << a * b / max<<'\n';
	}
}