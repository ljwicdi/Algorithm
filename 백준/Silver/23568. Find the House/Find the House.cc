
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, pair<char, int>> myMap;
    int orderNum, i, k, start;
    char j;
    
    cin >> orderNum;
    
    for(int l=0; l<orderNum; l++)
    {
        cin >> i >> j >> k;
        
        myMap[i] = make_pair(j, k);
    }
    
    cin >> start;
    
    for(int l=0; l<orderNum; l++)
    {
        if(myMap[start].first == 'L')
        {
            start = start - myMap[start].second;
        }
        else
        {
            start = start + myMap[start].second;
        }
    }
    
    cout << start;
    return 0;
}
