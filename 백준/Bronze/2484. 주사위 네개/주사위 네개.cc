#include <iostream>
using namespace std;
int main() 
{
	int n, total =0;
	cin >> n;
	while (n--) {
		int arr[7] = { 0, };
		
		// 1. 입력부
		for (int i = 0; i < 4; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp]++;
		}

		// 2. 조건부
		for (int j = 6; j > 0; j--) {
			if (arr[j] == 4) {
				total = total < 50000 + 5000 * j ? 50000 + 5000 * j : total;
				break;
			}
			else if (arr[j] == 3) {
				total = total < 10000 + 1000 * j ? 10000 + 1000 * j : total;
				break;
			}

			else if (arr[j] == 2) {

				for (int k = j - 1; k > 0; k--) {
					if (arr[k] == 2) {
						total = total < 2000 + j * 500 + k * 500 ? 2000 + j * 500 + k * 500 : total;
						break;
					}
					else {
						total = total < 1000 + 100 * j ? 1000 + 100 * j : total;
					}
				}
				break;
			}

			else if(arr[j] == 1) {
				total = total < 100 * j ? 100 * j : total;
			}
		}
	}

	cout << total;
}