#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int clusterPeople = 2;
    while (1) {
        // 현재 라운드
        answer++;
        // 덩어리 식별
        int clusterId = 0;
        int t1, t2;
        int index = clusterPeople;
        int before = 0;
        while (index <= n) {
            for (int i = before; i < index; i++) {
                if ((i + 1) == a) {
                    t1 = clusterId;
                }
                if ((i + 1) == b) {
                    t2 = clusterId;
                }
            }
            before = index;
            index = index + clusterPeople;
            clusterId++;
        }
        if (t1 == t2) {
            break;
        }
        clusterPeople = clusterPeople * 2;
    
    }
    return answer;
}