
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    
    if (n >= 1 && n <= 4) {
        cout << v[n];
        exit(0);
    }
    
    int i = 5;
    int result;
    while (1) {
        vector<int> temp;
        if (i % 3 == 0) {
            temp.push_back(v[i / 3] + 1);
        }
        if (i % 2 == 0) {
            temp.push_back(v[i / 2] + 1);
        }
        temp.push_back(v[i - 1] + 1);
        sort(temp.begin(), temp.end());
        v.push_back(temp[0]);
        if (i == n) {
            result = temp[0];
            break;
        }
        i++;
    }

    cout << result;
    return 0;
}
