#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int m, n;
    set<pair<int, int>> picture;
    vector<pair<int, int>> v;
    vector<pair<int, int>> dif;
    cin>>m;
    int x, y;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    cin>>n;
    
    int compx = v[0].first;
    int compy = v[0].second;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        dif.push_back(make_pair(x-compx, y-compy));
        picture.insert(make_pair(x, y));
    }

    int cnt;
    
    for(int i=0; i<dif.size(); i++)
    {
        cnt = 0;
        
        for(int j=0; j<v.size(); j++)
        {
            if(picture.find(make_pair(v[j].first+dif[i].first, v[j].second+dif[i].second)) != picture.end())
            {
                cnt++;
            }
            if(cnt == m)
            {
                cout<<dif[i].first<<" "<<dif[i].second;
                return 0;
            }
        }
    }
    
    
    
    return 0;
}
