
#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    vector<pair<string, int>> v;
    string str;
    for (int i = 0; i < 7; i++) {
        getline(cin, str);
        int index = 0;
        string name = "";
        while (str[index] != ' ') {
            name += str[index];
            index++;
        }
        index++;
        string num = "";
        while (index != str.length()) {
            num += str[index];
            index++;
        }
        v.push_back(make_pair(name, stoi(num)));
    }
    
    string result;
    int ma = -1;
    for (auto s : v) {
        if (ma < s.second) {
            ma = s.second;
            result = s.first;
        }
    }
    cout << result;
    return 0;
}