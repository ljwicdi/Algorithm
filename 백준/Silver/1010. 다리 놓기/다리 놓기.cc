#include <iostream>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    for(int i=0; i<testCase; i++)
    {
        int N, M;
        cin >> N >> M;
        long long dp[40][40] = {0, };
    
        for(int i=1; i<=29; i++)
            dp[1][i] = i;
        
        
        for(int i=2; i<=29; i++)
        {
            for(int j=2; j<=29; j++)
            {
                for(int k=j-1; k>=1; k--)
                {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    
        cout << dp[N][M] << "\n";
    }
    
    return 0;
}
