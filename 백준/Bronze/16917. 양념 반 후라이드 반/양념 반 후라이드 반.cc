#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int A, B, C, X, Y;
    
    cin >> A >> B >> C >> X >> Y;
    
    int mi, ma;
    string miName;
    if (X < Y) {
        mi = X;
        ma = Y;
        miName = "Yang";
    } else {
        mi = Y;
        ma = X;
        miName = "Fried";
    }
    
    long long sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    
    if (miName == "Yang") {
        sum1 = sum1 + mi * C * 2 + (ma - mi) * B;
    } else {
        sum1 = sum1 + mi * C * 2 + (ma - mi) * A;
    }
    
    sum2 = sum2 + ma * C * 2;
    
    sum3 = sum3 + (mi * A) + (mi * B) + (ma - mi) * C * 2;
    sum4 = sum4 + X * A + Y * B;
    
    vector<int> v;
    v.push_back(sum1);
    v.push_back(sum2);
    v.push_back(sum3);
    v.push_back(sum4);
    
    sort(v.begin(), v.end());
    
    cout << v[0];
    return 0;
}
