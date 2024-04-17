#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0";
        exit(0);
    }
    int subCnt;
    
    double temp = n * 0.15;
    if (temp - (int)temp >= 0.5) {
        subCnt = (int)(temp + 1);
    } else {
        subCnt = (int)temp;
    }
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int sum = 0;
    for (int i = subCnt; i < v.size() - subCnt; i++) {
        sum += v[i];
    }
    
    double result;
    double avg = (double)sum / (n - 2*subCnt); 
    if (avg - (int)avg >= 0.5) {
        result = (int)(avg + 1);
    } else {
        result = (int)avg;
    }
    
    cout << result;
    return 0;
}
