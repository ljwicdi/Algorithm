
#include <iostream>
using namespace std;
int main() {
    
    int N, M, L;
    cin >> N >> M >> L;
    
    int ballCnt = 0, currentBall = 1;
    int recievedCnt[N + 1] = {0, };
    
    while (1) {
        
        recievedCnt[currentBall]++;
        
        if (recievedCnt[currentBall] == M) break;
        
        // 만약 현재 볼을 받은 사람의 누적된 받은 횟수가 홀수라면
        if (recievedCnt[currentBall] % 2 == 1) {
            // 시계방향으로 L만큼 볼을 던짐
            if (currentBall + L > N) {
                currentBall = (currentBall + L) % N;
            } else {
                currentBall = currentBall + L;
            }
        } else {
            // 반시계방향으로 l만큼 볼을 던짐 
            if (currentBall - L < 1) {
                currentBall = N - (L - currentBall);
            } else {
                currentBall = currentBall - L;
            }
        }
        
        ballCnt++;
    }
    
    cout << ballCnt;
    return 0;
}
