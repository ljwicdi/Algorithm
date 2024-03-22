#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
   
    int sum = 1;
    vector<int> s;
    for (int i = 1; i <= n; i++) {
        s.push_back(i);
    }
    
    int i = 0, j = 0;
    while (1) {
        if (sum == n) {
            answer++;
            j++;
            if (j!=n) sum = sum + s[j];
        } 
        if (i == j) {
            j++;
            if (j!=n) sum = sum + s[j];
        }
        if (j == n) {
            break;
        }
        
        if (sum > n) {
            sum = sum - s[i];
            i++;
        } else if (sum < n) {
            j++;
            if (j != n)
                sum = sum + s[j];
        }
    }
    return answer;
}