#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class comp
{
public:
    bool operator() (int a, int b)
    {
        return a>b;
    }
};

int main(void)
{
    priority_queue<int, vector<int>, comp> pq;
    int N;
    int data;
    int temp1, temp2;
    int result = 0;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>data;
        pq.push(data);
    }
    while(1)
    {
        temp1 = pq.top();
        pq.pop();
        if(pq.empty())
            break;
        temp2 = pq.top();
        pq.pop();
        result = result + temp1 + temp2;
        pq.push(temp1+temp2);
    
    }
    cout<<result;
    return 0;
}