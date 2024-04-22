
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        int n;
        cin >> n;
        string data;
        map<string, int> myMap;
        vector<string> v;
        bool flag = false;
        for (int j = 0; j < n; j++) {
            cin >> data;
            v.push_back(data);
            myMap[data]++;
            if (myMap[data] >= 3) {
                flag = true;
            }
        }
        
        if (n >= 48) {
            cout << "0\n";
            continue;
        }
        
        
        int mi = 99999999;
        for (int j = 0; j < v.size() - 2; j++) {
            for (int k = j + 1; k < v.size() - 1; k++) {
                for (int l = k + 1; l < v.size(); l++) {
                    int sum = 0;
                    string a = v[j];
                    string b = v[k];
                    string c = v[l];
                    
                    for (int m = 0; m < 4; m++) {
                        if (a[m] != b[m]) {
                            sum++;
                        }
                        if (b[m] != c[m]) {
                            sum++;
                        }
                        if (a[m] != c[m]) {
                            sum++;
                        }
                    }
                    
                    if (mi > sum) {
                        mi = sum;
                    }
                }
            }
        }
        
        cout << mi << "\n";
        
    }
    return 0;
}
