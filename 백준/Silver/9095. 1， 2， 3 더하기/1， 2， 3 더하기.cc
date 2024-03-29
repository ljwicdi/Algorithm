
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    for (int i = 4; i < 11; i++) {
        v.push_back(v[i - 3] + v[i - 2] + v[i - 1]);
    }
    int n;
    for (int i = 0; i < testCase; i++) {
        cin >> n;
        
        cout << v[n] << "\n";
    }
    return 0;
}
