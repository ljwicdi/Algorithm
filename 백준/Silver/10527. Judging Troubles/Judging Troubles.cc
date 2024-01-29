
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    map<string, int> myMap;
    string str;
    int cnt = 0;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> str;
        if(myMap.find(str) == myMap.end())
            myMap[str] = 1;
        else
            myMap[str]++;
    }
    
    for(int i=0; i<N; i++)
    {
        cin >> str;
        if(myMap.find(str) != myMap.end())
        {
            if(myMap[str] > 0)
            {
                myMap[str]--;
                cnt++;
            }
        }
    }
    
    cout << cnt;
    return 0;
}
