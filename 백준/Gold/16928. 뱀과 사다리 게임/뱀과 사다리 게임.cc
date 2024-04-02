    
    #include <iostream>
    #include <vector>
    #include <map>
    #include <queue>
    using namespace std;
    int main()
    {
        map<int, int> myMapUp;
        map<int, int> myMapDown;
        int N, M;
        cin >> N >> M;
        
        int x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            myMapUp[x] = y;
        }
        
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            myMapDown[x] = y;
        }
        
        
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<bool> visited(101, false);
        
        int result = 0;
        
        int d[6] = {1, 2, 3, 4, 5, 6};
        while (!q.empty()) {
            auto s = q.front();
            
            if (s.first == 100) {
                result = s.second;
                break;
            }
            q.pop();
            
            for (int i = 0; i < 6; i++) {
                int next = s.first + d[i];
                
                if (next > 100) continue;
                
                // 사다리가 존재하면 
                if (myMapUp.find(next) != myMapUp.end()) {
                    // 사다리로 넘어간 곳이 아직 방문하지 않은 곳이면 
                    if (visited[next] == false) {
                        visited[next] = true;
                        q.push({myMapUp[next], s.second + 1});
                    }
                    continue;
                }
                
                // 뱀이 존재한다면 
                if (myMapDown.find(next) != myMapDown.end()) {
                    if (visited[next] == false) {
                        visited[next] = true;
                        q.push({myMapDown[next], s.second + 1});
                    }
                    continue;
                }
                
                // 뱀과 사다리 모두 존재하지 않다면 
                if (visited[next] == false) {
                    visited[next] = true;
                    q.push({next, s.second + 1});
                }
            }
        }
        cout << result;
        return 0;
    }
