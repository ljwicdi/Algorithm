#include <iostream>
using namespace std;
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    
    int newMan, newWoman;
    int maxTeamCnt = -1;
    int teamCnt;
    for (int i = 0; i <= K; i++) {
        newMan = M - i;
        newWoman = N - (K - i);
        
        if (newWoman / 2 > newMan) {
            teamCnt = newMan;
        } else {
            teamCnt = newWoman / 2;
        }
        
        
        if (teamCnt > maxTeamCnt) {
            maxTeamCnt = teamCnt;
        }
    }
    
    cout << maxTeamCnt;

    return 0;
}
