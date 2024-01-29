
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N, M;
    int data;
    cin >> N >> M;
    
    vector<int> v1, v2;
    
    for(int i=0; i<N; i++)
    {
        cin >> data;
        v1.push_back(data);
    }
    
    for(int i=0; i<M; i++)
    {
        cin >> data;
        v2.push_back(data);
    }
    
    int Ap = 0, Bp = 0; // a 시작, b 시작 포인터
    
    vector<int> result; // 합친 결과를 담을 벡터
    while(1)
    {
        if(v1[Ap] <= v2[Bp])
        {
            result.push_back(v1[Ap]);
            Ap++;
        }
        else
        {
            result.push_back(v2[Bp]);
            Bp++;
        }
        
        if(Ap == v1.size())
        {
            for(int j=Bp; j<v2.size(); j++)
            {
                result.push_back(v2[j]);
            }
            break;
        }
        else if(Bp == v2.size())
        {
            for(int j=Ap; j<v1.size(); j++)
            {
                result.push_back(v1[j]);
            }
            break;
        }
    }

    for(auto s : result)
        cout << s << " ";
    return 0;
}
