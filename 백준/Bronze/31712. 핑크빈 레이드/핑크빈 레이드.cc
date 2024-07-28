#include <iostream>
#include <queue>
using namespace std;
int main() {
    
    int cu, du, cd, dd, cp, dp, bossHp;
    cin >> cu >> du;
    cin >> cd >> dd;
    cin >> cp >> dp;
    cin >> bossHp;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push(make_pair(cu, make_pair(du, 0)));
    pq.push(make_pair(cd, make_pair(dd, 1)));
    pq.push(make_pair(cp, make_pair(dp, 2)));
    
    int t = 0;
    bossHp -= du;
    bossHp -= dd;
    bossHp -= dp;
    
    while (bossHp > 0) {
        auto node = pq.top();
        pq.pop();
        t = node.first;
        if (node.second.second == 0) {
            pq.push(make_pair(t + cu, make_pair(node.second.first, 0)));
        } else if (node.second.second == 1) {
            pq.push(make_pair(t + cd, make_pair(node.second.first, 1)));
        } else if (node.second.second == 2) {
            pq.push(make_pair(t + cp, make_pair(node.second.first, 2)));
        }
        
        bossHp = bossHp - node.second.first;
    }
    
    cout << t;

    return 0;
}