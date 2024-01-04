#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;



int main()
{
    deque<char> s1;
    stack<char> s2;
    string str;
    string boom;
    cin>>str;
    cin>>boom;
    int strsize = str.length();
    int boomsize = boom.length();
    int index;
    for(int i=0; i<strsize; i++)
    {
        index = boomsize-1;
        if(s1.size() < boomsize)
        {
            s1.push_back(str[i]);
            continue;
        }
        while(1)
        {
            if(s1.back() != boom[index])
            {
                while(!s2.empty())
                {
                    s1.push_back(s2.top());
                    s2.pop();
                }
                break;
            }
            s2.push(s1.back());
            s1.pop_back();
            index--;
            if(index < 0 )
            {
                while(!s2.empty())
                {
                    s2.pop();
                }
                break;
            }
            
                
        }
        s1.push_back(str[i]);
        
    }
    
    index = boomsize-1;
    if(s1.empty())
    {
        cout<<"FRULA";
        return 0;
    }
    
    while(1)
    {
        
        if(s1.back() != boom[index])
        {
            while(!s2.empty())
            {
                s1.push_back(s2.top());
                s2.pop();
            }
            break;
        }
        s2.push(s1.back());
        s1.pop_back();
        index--;
        
        if(s1.empty() && index >=0)
        {
            while(!s2.empty())
            {
                s1.push_back(s2.top());
                s2.pop();
            }
            break;
        }
        
        if(index < 0 || s1.empty())
            break;
    }
    
    if(s1.empty())
    {
        cout<<"FRULA";
        return 0;
    }

    while(!s1.empty())
    {
        cout<<s1.front();
        s1.pop_front();
    }
    return 0;
    
}
