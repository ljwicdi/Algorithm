#include <iostream>

using namespace std;



int main()
{
    long long S;
    cin >> S;
    
    long long sum = 0;
    long long cnt = 1;
    long long result = 0;
    while(sum <= S)
    {
        sum = sum + cnt;
        cnt = cnt + 1;
        result++;
    }
    
    cout << result-1;
    return 0;
}
