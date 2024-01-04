
#include <iostream>

using namespace std;

typedef struct xy{
    int x;
    int y;
} XY;

int ccw(XY p1, XY p2, XY p3)
{
    int result = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
    
    if(result > 0)
    {
        return 1;
    }
    else if(result == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    XY p1;
    XY p2;
    XY p3;
    
    cin>>p1.x>>p1.y;
    cin>>p2.x>>p2.y;
    cin>>p3.x>>p3.y;
    
    cout<<ccw(p1, p2, p3);

    return 0;
}
