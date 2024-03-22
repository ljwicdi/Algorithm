#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int n)
{
    // 앞으로만 감 
    int ans = 0;
    while (1) {
        if (n == 1) {
            break;
        }
        if (n % 2 != 0) {
            ans++;
            n--;
        }
        n = n / 2;
        if (n == 1) {
            break;
        }
    }
    ans++;
    return ans;
}