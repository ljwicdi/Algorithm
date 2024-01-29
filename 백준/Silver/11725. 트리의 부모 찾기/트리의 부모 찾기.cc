
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    // 간선의 정보 중 가장 첫번째 정보가 루트다.
    
    int N;
    int a, b;
    queue<int> q;
    cin >> N;
    vector<int> e[N+1];
    
    for(int i=0; i<N-1; i++)
    {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    
    int result[N+1];
    int v;
    q.push(1);
    
    int visited[N+1] = {false, };
    visited[1] = true;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(auto s : e[v])
        {
            if(visited[s] == true)
                continue;
            result[s] = v;
            q.push(s);
            visited[s] = true;
            
        }
    }
    
    for(int i=2; i<=N; i++)
        cout << result[i] << "\n";

    return 0;
}
