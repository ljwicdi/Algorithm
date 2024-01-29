
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int Aa, Bb, Gg;
    int aScore = 0, bScore = 0;
    string str;
    cin >> Aa >> Bb >> Gg;
    
    map<string, int> A;
    map<string, int> B;
    
    for(int i=0; i<Aa; i++)
    {
        cin >> str;
        A[str] = 1;
    }
       
    for(int i=0; i<Bb; i++)
    {  
        cin >> str;
        B[str] = 1;
    }

    for(int i=0; i<Gg; i++)
    {
        cin >> str;
        
        if(A.find(str) == A.end())
        {
            bScore++;
        }
        else
        {
            aScore++;
        }
    }
    
    if(aScore > bScore)
        cout << "A";
    else if(aScore < bScore)
        cout << "B";
    else
        cout << "TIE";
    return 0;
}
