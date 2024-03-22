#include <string>
#include <vector>

using namespace std;

int change (int n) {
    int result = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            result++;
        }
        n = n / 2;
    }
    return result;
}

int solution(int n) {
    int answer = 0;

    for (int i = n + 1; i <= 1000000; i++) {
        if (change(n) == change(i)) {
            answer = i;
            break;
        }
    }
    return answer;
}