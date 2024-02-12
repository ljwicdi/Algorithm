
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main()
{
    int N;
    cin >> N;
    vector<int> x;
    vector<int> y;
    int xx, yy;
    for (int i = 0; i < N; i++) {
        cin >> xx >> yy;
        x.push_back(xx);
        y.push_back(yy);
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int minX = x[0];
    int maxX = x[x.size() - 1];
    int minY = y[0];
    int maxY = y[y.size() - 1];
    
    int S = (maxX - minX) * (maxY - minY);
    
    cout << S;
    
    return 0;
}
