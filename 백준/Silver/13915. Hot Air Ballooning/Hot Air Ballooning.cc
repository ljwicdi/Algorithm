
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    
    string str;
    while(cin >> N)
    {
        set<set<char>> mySet;
        for(int i=0; i<N; i++)
        {
            cin >> str;
            set<char> s;
            for(int j=0; j<str.length(); j++)
            {
                s.insert(str[j]);
            }
            mySet.insert(s);
        }
        cout << mySet.size() << "\n";
    }

    return 0;
}
