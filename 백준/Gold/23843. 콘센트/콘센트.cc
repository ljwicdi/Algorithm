#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    if(a > b)
        return true;
    else
        return false;
}
int main()
{
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;   // 최소힙
    vector<int> v;
    int junNum, conNum;
    int t;
    cin>>junNum>>conNum;
    
    for(int i=0; i<junNum; i++)
    {
        cin>>t;
        v.push_back(t);
    }

    sort(v.begin(), v.end(), comp); // 내림차순 정렬
    
    for(int i=0; i<conNum; i++)
    {
        pq.push(v[i]);  // 일단 콘센트에 전자제품 꽂음 
    }
    
    int minus; // 큐에 있는 원소 시간 다 차감
    
    for(int j=conNum; j<v.size(); j++)
    {
        vector<int> temp;
        minus = pq.top();
        result = result + pq.top();
        pq.pop();
        while(!pq.empty())
        {
            temp.push_back(pq.top()-minus);
            pq.pop();
        }
        for(int i=0; i<temp.size(); i++)
        {
            pq.push(temp[i]);
        }
        pq.push(v[j]);
    }
    
    while(!pq.empty())
    {
        vector<int> temp;
        minus = pq.top();
        result = result + pq.top();
        pq.pop();
        while(!pq.empty())
        {
            temp.push_back(pq.top()-minus);
            pq.pop();
        }
        for(int i=0; i<temp.size(); i++)
        {
            pq.push(temp[i]);
        }
        
    }
    cout<<result;
    
    return 0;
}
