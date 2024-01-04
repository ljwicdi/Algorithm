#include <iostream>
using namespace std;

int ids[1000001];
int siz[1000001];
int root(int i)
{
    while(i!=ids[i])
    {
        i = ids[i];
    }
    return i;
}

bool find(int node1, int node2)
{
    if(root(node1) ==  root(node2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void uni(int node1, int node2)
{
    if(root(node1) == root(node2))  return; // 같은 집합일 때

    int a = root(node1);
    int b = root(node2);
    if(siz[a] >= siz[b])
    {
        ids[b] = a;
        siz[a] += siz[b];
    }
    else
    {
        ids[a] = b;
        siz[b] += siz[a];
    }


}

int main(void)
{
    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int n, m;
    int order;
    int node1, node2;
    cin>>n>>m;

    // 노드 초기화
    for(int i=0; i<=n; i++)
    {
        ids[i] = i;
        siz[i] = 1;
    }

    for(int i=0; i<m; i++)
    {
        cin>>order>>node1>>node2;
        if(order == 0)
        {
            uni(node1, node2);
        }
        else
        {
            if(find(node1, node2))
            {
                cout<<"YES"<<"\n";
            }
            else
            {
                cout<<"NO"<<"\n";
            }
        }
    }
    return 0;
}