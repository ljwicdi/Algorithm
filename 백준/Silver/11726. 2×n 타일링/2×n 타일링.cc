
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
    v.push_back(2);
    if (n == 1 || n == 2) {
        cout << v[n];
        exit(0);
    }
    int i = 3;
    int result;
    while (1) {
        v.push_back((v[i - 1] + v[i - 2]) % 10007);
        if (i == n) {
            result = v[i] % 10007;
            break;
        }
        i++;
    }
    cout << result;
    return 0;
}
