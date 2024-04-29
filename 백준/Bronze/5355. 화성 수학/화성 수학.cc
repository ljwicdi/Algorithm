
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    
    cout << fixed;
    cout.precision(2);
    int testCase;
    cin >> testCase;
    cin.ignore();
    for (int i = 0; i < testCase; i++) {
        string str;
        getline(cin, str);
        
        int index = 0;
        vector<string> v;
        while (index < str.length()) {
            string temp = "";
            while (str[index] != ' ' && index < str.length()) {
                temp += str[index];
                index++;
            }
            v.push_back(temp);
            index++;
        }
        
        double start = stod(v[0]);
        
        for (int j = 1; j < v.size(); j++) {
            if (v[j] == "@") {
                start = start * 3;
            } else if (v[j] == "%") {
                 start = start + 5;
            } else if (v[j] == "#") {
                 start = start - 7;
            }
        }
        cout << start << "\n";
    }
    return 0;
}
