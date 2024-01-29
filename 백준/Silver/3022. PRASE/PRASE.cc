
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    map<string, int> myMap;
    string str;
    int cnt = 0;
    int result = 0;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> str;
        
        if(myMap.find(str) == myMap.end())
        {
            myMap[str] = 1;
            cnt++;
        }
        else
        {
            if(cnt - myMap[str] < myMap[str])
            {
                myMap[str]++;
                result++;
                cnt++;
            }
            
            else
            {
                myMap[str]++;
                cnt++;
            }
        }
    }
    
    cout << result;
    return 0;
}
