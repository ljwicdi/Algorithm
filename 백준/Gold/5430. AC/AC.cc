#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void)
{
    int testCase;
    
    
    int n;
    cin>>testCase;
    for(int i=0; i<testCase; i++)
    {
        deque<int> myDeque;
        string order;
        string arr;
        int pos = 0;
        int errorChk = 0;
        cin>>order;
        cin>>n;
        cin>>arr;
        int tempIdx;
        int j = 0;
        int chk = 0;
        string temp;
        while(1)
        {
            
            if(n==0)
                break;
            temp.clear();
            tempIdx = 0;
            while(arr[j]!=',')
            {
                
                if(arr[j]>= 48 && arr[j] <= 57)
                {
                    temp+=arr[j];
                    
                }
                j++;
                
                if(j == arr.length())
                {
                    chk = 1;
                    break;
                }
            }
        
            myDeque.push_back(stoi(temp));
            
            
            
            if(chk == 1)
                break;
            
            
            if(j == arr.length())
            {
                break;
            }
            j++;
        }
        for(int l=0; l<order.length(); l++)
        {
            if(order[l] == 'R')
            {
                if(pos == 0)
                    pos = 1;
                else
                    pos = 0;
            }
            else if(order[l] == 'D')
            {
                if(pos == 1)
                {
                    if(!myDeque.empty())
                        myDeque.pop_back();
                    else
                    {
                        cout<<"error"<<"\n";
                        errorChk = 1;
                        break;
                    }
                }
                else
                {
                    if(!myDeque.empty())
                        myDeque.pop_front();
                    else
                    {
                        cout<<"error"<<"\n";
                        errorChk = 1;
                        break;
                    }
                }
            }
        }
        if(errorChk == 1)
            continue;
        int size = myDeque.size();
        
        if(pos == 0)
        {
            cout<<"[";
            for(int p=0; p<size; p++)
            {
                if(p!=size-1)
                    cout<<myDeque.front()<<",";
                else
                    cout<<myDeque.front();
                myDeque.pop_front();
            }
            cout<<"]";
        }
        else
        {
            cout<<"[";
            for(int p=0; p<size; p++)
            {
                if(p!=size-1)
                    cout<<myDeque.back()<<",";
                else
                    cout<<myDeque.back();
                myDeque.pop_back();
            }
            cout<<"]";
        }
        cout<<"\n";
    
    }
    
    return 0;
}