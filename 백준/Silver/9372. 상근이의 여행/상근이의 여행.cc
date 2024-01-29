#include <iostream>

using namespace std;

int main()
{
    int testCase;
    int N, M;
    int a, b;
    cin >> testCase;
    
    for(int i=0; i<testCase; i++)
    {
        cin >> N >> M;
        
        for(int j=0; j<M; j++)
        {
            cin >> a >> b;
        }
        
        cout << N -1 << "\n";
    }

    return 0;
}
