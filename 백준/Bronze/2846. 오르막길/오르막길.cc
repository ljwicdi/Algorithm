#include <iostream>
using namespace std;

int main() {
	int n, MAX =0 , begin =0;
	
	
	cin >> n >> begin;
	int diff = 0; n--;
	while (n--) {
		int tmp; cin >> tmp;
		if (tmp > begin) {
			diff += (tmp - begin);
		}
		else {
			MAX = MAX < diff ? diff : MAX;
			diff = 0;
		}
		
		begin = tmp;
	}

	MAX = MAX < diff ? diff : MAX;
	cout << MAX;
}
