#include <iostream>
#include <vector>
using namespace std;

int digitSum(int i) {
    int sum = 0;
    
    while (i != 0) {
        sum = sum + i % 10;
        i = i / 10;
    }
    
    return sum;
}
int main()
{
    // 1부터 구해나가는 방식
    // N이 구해지면 리턴하자
    int N;
    cin >> N;
    // 구해지지 못하는 경우
    int i = 0;
    int result = 0;
    while (1) {
        int sum = digitSum(i);
        if (sum + i == N) {
            result = i;
            break;
        }
        i++;
        if (i == 1000000) {
            break;
        }
    }
    
    cout << result;
    return 0;
}
