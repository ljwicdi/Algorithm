
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int N;  // 후보수
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

    int max = -1;
    
    for(auto s : myMap) // 최대 투표수 찾기
    {
        if(max < s.second)
            max = s.second;
    }
    
    vector<string> v;
    
    for(auto s : myMap)
    {
        if(s.second == max)
            v.push_back(s.first);
    }
    
    for(auto s : v)
        cout << s << "\n";
    
    
    return 0;
}
