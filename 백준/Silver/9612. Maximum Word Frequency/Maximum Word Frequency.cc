
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    string str;
    map<string, int> myMap;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> str;
        
        if(myMap.find(str) == myMap.end())
            myMap[str] = 1;
        else
            myMap[str]++;
    }
    
    string result;
    int cnt;
    for(auto s : myMap)
    {
        result = s.first;
        cnt = s.second;
    }
    
    cout << result << " " << cnt;
    return 0;
}
