

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.first < b.first)
        return true;
    else
        return false;
}


int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    
    vector<pair<int, int>> v;
    
    int N;
    int result = 0;
    int a, b, c;
    cin>>N;
    
    for(int i=0; i<N; i++)
    {
        cin>>a>>b>>c;
        
        v.push_back(make_pair(b, c));
    }
    
    sort(v.begin(), v.end(), comp);

    pq.push(v[0].second);
    result = result + 1;
    
    for(int i=1; i<v.size(); i++)
    {
        if(v[i].first < pq.top())
        {
            pq.push(v[i].second);
            result = result + 1;
        }
        else
        {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    
    cout<<result;
    
    return 0;
}
