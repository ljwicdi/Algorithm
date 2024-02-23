#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while (1) {
        answer.push_back(n % 10);
        n = n / 10;
        if (n == 0) break;
    }
    return answer;
}