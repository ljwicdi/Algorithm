#include<iostream>
using namespace std;

int main() {
	int L, K;
	cin >> L >> K;
	// L길이의 array 생성 후 초기화
	bool* array = new bool[L];
	for (int i = 0; i < L; i++) {
		array[i] = false;
	}

	int a, b;
	int max1=0, max2=0;
	int index_max1=0, index_max2=0; //방청객 번호를 출력해야되기 때문에 따로 저장할 것을 또 만들었다.
	for (int i = 0; i < K; i++) {  //순서대로 비교하기 때문에 따로 저장할 필요없이 반복 입출력을 받아 마지막에 출력하면된다.
		cin >> a >> b;
		if (max1 < b - a + 1) {  // 첫번째 출력값
			max1 = b - a + 1;
			index_max1 = i;
		}

		int cnt = 0;
		for (int k = 0; k < b - a + 1; k++) {  // 두번째 출력값
			if (array[a - 1 + k] == false) {
				array[a - 1 + k] = true;
				cnt++;
			}
		}
		
		if (max2 < cnt) {
			max2 = cnt;
			index_max2 = i;
		}
	}
	cout << index_max1 + 1 << endl;
	cout << index_max2 + 1 << endl;
}