
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    if (n == 1) {
        cout << 1;
        exit(0);
    }
    
    int i = 2;
    while (1) {
        v.push_back(v[i - 1] + v[i - 2]);
        if (i == n) {
            break;
        }
        i++;
    }
    cout << v[i];
    return 0;
}
