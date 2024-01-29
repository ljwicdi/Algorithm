
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int testCase;
    string str;
    map<string, int> myMap;
    
    cin >> testCase;
    
    for(int i=0; i<testCase; i++)
    {
        cin >> str;
        
        int idx = 0;
        
        while(1)
        {
            if(idx >= str.length())
                    break;
            string temp;
            string itemp;
            int flag = 0;
            while(1)
            {
                if(str[idx] == ':')
                {
                    idx = idx+1;
                    flag = 1;
                    continue;
                }
                
                if(flag == 1)
                {
                    while(idx < str.length() && str[idx] != ',')
                    {
                        itemp = itemp + str[idx];
                        idx = idx + 1;
                    }
                    
                    myMap[temp] = stoi(itemp);
                    idx = idx + 1;
                    break;
                }
                
                
                temp = temp + str[idx];
                idx = idx + 1;
            }
        }
        
        cin >> str;
        idx = 0;
        string temp;
        int min = 2000;
        while(1)
        {
            if(idx >= str.length())
                    break;
            int max = -9999;
            
            while(1)
            {
                
                if(str[idx] == '|')
                {
                    if(myMap[temp] > max)
                    {
                        max = myMap[temp];
                    }
                    idx = idx + 1;
                    temp.clear();
                    break;
                }
                if(str[idx] == '&')
                {
                    if(myMap[temp] > max)
                    {
                        max = myMap[temp];
                    }
                    idx = idx + 1;
                    temp.clear();
                    continue;
                }
                
                temp = temp + str[idx];
                idx = idx + 1;
                if(idx >= str.length())
                {
                    if(myMap[temp] > max)
                    {
                        max = myMap[temp];
                    }
                    break;
                }
                
            }
            
            if(max < min)
                min = max;
        }
        
        cout << min << "\n";
    }
    
   
    return 0;
}
