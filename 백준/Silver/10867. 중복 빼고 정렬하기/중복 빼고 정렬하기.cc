
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> mySet;
    vector<int> v;
    int N;
    int data;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> data;
        mySet.insert(data);
    }
    
    for(auto s : mySet)
    {
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    
    for(auto s : v)
        cout << s << " ";
    
    return 0;
}
