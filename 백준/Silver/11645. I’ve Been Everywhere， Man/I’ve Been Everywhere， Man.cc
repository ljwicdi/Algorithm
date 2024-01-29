
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int testCase, N;
    string city;
    cin >> testCase;
    
    for(int i=0; i<testCase; i++)
    {
        cin >> N;
        set<string> mySet;
        for(int j=0; j<N; j++)
        {
            cin >> city;
            
            mySet.insert(city);
        }
        
        cout << mySet.size() << "\n";
    }

    return 0;
}
