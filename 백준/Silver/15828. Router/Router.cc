
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    
    int bufferSize;
    int data;
    
    cin >> bufferSize;
    
    while(1)
    {
        cin >> data;
        
        if(data == -1)
            break;
        
        if(data == 0)   // 라우터가 데이터 처리
        {
            q.pop();
        }
        else if(data > 0)
        {
            if(q.size() ==bufferSize)
            {
                continue;
            }
            q.push(data);
        }
    }
    
    
    if(q.empty())
    {
        cout << "empty";
    }
    else
    {
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
    return 0;
}
