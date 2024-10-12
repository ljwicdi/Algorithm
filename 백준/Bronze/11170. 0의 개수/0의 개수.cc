#include <stdio.h>
// [baekjoon] 11170번 - 0의 개수

int check_0(int n, int m) {
	int cnt = 0;
	for (int i = n; i <= m; i++) {
		if (i == 0) cnt++;
		int i2 = i;

		while (i2 > 0) {
			if (i2 % 10 == 0)cnt++;
			i2 /= 10;
		}

	}
	return cnt;
}

int main() {

	int T, N, M;
	scanf("%d", &T);	

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%d\n", check_0(N, M));
	}

}