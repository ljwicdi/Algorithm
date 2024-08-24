#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
   
   int N, K;
   cin >> N >> K;
   
   queue<pair<int, int>> q;
   q.push(make_pair(N, 0));
   int t = 0, cnt = 0;
   int visited[200000];
   
   for (int i = 0; i < 200000; i++) {
       visited[i] = 2000000000;
   }
   while (!q.empty()) {
       auto s = q.front();
     
       if (t == 0 && s.first == K) {
           t = s.second;
           cnt++;
           q.pop();
           continue;
       } else if (t != 0 && s.first == K && t == s.second) {
           cnt++;
           q.pop();
           continue;
       } else if (t != 0 && t < s.second) {
           q.pop();
           continue;
       }
       
       q.pop();
       
       if (s.first - 1 >= 0 && visited[s.first - 1] >= s.second + 1) {
           q.push(make_pair(s.first - 1, s.second + 1));
           visited[s.first - 1] = s.second + 1;
       }
       
       if (s.first + 1 <= 200000 && visited[s.first + 1] >= s.second + 1) {
           q.push(make_pair(s.first + 1, s.second + 1));
           visited[s.first + 1] = s.second + 1;
       }
       
       if (s.first * 2 <= 200000 && visited[s.first * 2] >= s.second + 1) {
           q.push(make_pair(s.first * 2, s.second + 1));
           visited[s.first * 2] = s.second + 1;
       }
   }
   
   cout << t << "\n";
   cout << cnt;
   
   return 0;
}