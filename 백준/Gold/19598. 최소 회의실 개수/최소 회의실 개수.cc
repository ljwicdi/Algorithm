
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;
    int N;
    int start, end;
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        cin>>start>>end;
        v.push_back(make_pair(start, end));
    }
    
    sort(v.begin(), v.end());
    
    pq.push(v[0].second);
    
    for(int i=1; i<v.size(); i++)
    {
        if(v[i].first < pq.top())
        {
            pq.push(v[i].second);
        }
        else
        {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    
    cout<<pq.size();
    
}
