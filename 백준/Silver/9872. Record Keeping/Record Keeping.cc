
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    string str;
    map<vector<string>, int> myMap;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        vector<string> v;
        for(int j=0; j<3; j++)
        {
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end());
        if(myMap.find(v) == myMap.end())
            myMap[v] = 1;
        else
            myMap[v]++;
    }
    
    int max = -1;
    
    for(auto s : myMap)
    {
        if(max < s.second)
        {
            max = s.second;
        }
    }
    
    cout << max;
    return 0;
}
