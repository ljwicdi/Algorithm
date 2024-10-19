#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main()
{
	int board[101][101] = {0};
	int confetti;
	int row, column, width, height;

	scanf("%d", &confetti);

	for (int i = 1; i < confetti + 1; i++) {
		scanf("%d %d %d %d", &row, &column, &height, &width); // 너비랑 높이 바꿔서 입력되게 만들었음.
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				board[row][column+k] = i;
			}
			row++;
		}
	}

	int tocount = 1;
	int gat = 0;
	while(tocount < confetti + 1) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (board[i][j] == tocount) gat++;
			}
		}
		printf("%d\n", gat);
		tocount++;
		gat = 0;
	}
	
	return 0;
}