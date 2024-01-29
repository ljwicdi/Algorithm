#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int testCase;
    int N;
    int data;
    
    cin >> testCase;
    
    for(int i=0; i<testCase; i++)
    {
        vector<int> v;
        set<int> mySet;
        cin >> N;
        for(int j=0; j<N; j++)
        {
            cin >> data;
            
            v.push_back(data);
            mySet.insert(data);
        }
        sort(v.begin(), v.end());
        
         int cnt = 0; // result
    
        // ~ N^2
        for(int i=0; i<v.size()-1; i++)
        {
            for(int j=i+1; j<v.size(); j++)
            {
                if(mySet.find(v[j] + (v[j]-v[i])) != mySet.end())
                {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    
   
   
    
    
    return 0;
}
