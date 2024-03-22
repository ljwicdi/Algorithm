#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> sum;
    sum.push_back(0);
    sum.push_back(1);
    for (int i = 2; i <= n; i++) {
        sum.push_back((sum[i - 2] + sum[i - 1])% 1234567) ;
    }
    answer = sum[n];
    return answer;
}