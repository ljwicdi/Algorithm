
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    vector<vector<int>> v(15);
    v[0] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
    for (int i = 1; i <= 14; i++) {
        v[i].push_back(0);
        for (int j = 1; j <= 14; j++) {
            v[i].push_back(v[i][j - 1] + v[i - 1][j]);
        }
    }
    int n, k;
    
    for (int i = 0; i < testCase; i++) {
        cin >> k;
        cin >> n;
        
        cout << v[k][n] << "\n";
    }
    return 0;
}
