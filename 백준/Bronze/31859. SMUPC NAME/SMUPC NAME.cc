#include <iostream>
#include <set>
using namespace std;
int main() {
    int N;
    string str;
    cin >> N >> str;
    
    // 1
    set<char> mySet;
    string newStr = "";
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (mySet.find(str[i]) == mySet.end()) {
            mySet.insert(str[i]);
            newStr += str[i];
        } else {
            cnt++;
        }
    }
    
    // 2 
    newStr += to_string(cnt + 4);
    
    // 3
    newStr = to_string(N + 1906) + newStr;
    
    // 4
    string newNewStr = "";
    for (int i = newStr.length() - 1; i >= 0; i--) {
        newNewStr = newNewStr + newStr[i];
    }
    
    // 5
    newNewStr = "smupc_" + newNewStr;
    
    cout << newNewStr;
    return 0;
}