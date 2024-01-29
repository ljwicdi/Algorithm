#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
    {
        if(a.first < b.first)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int N;
    int x, y;
    vector<pair<int, int>> v;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> x >> y;
        
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(auto s : v)
    {
        cout << s.first << " " << s.second << "\n";
    }
    return 0;
}
