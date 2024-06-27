
#include <iostream>
#include <set>
using namespace std;
int main() {
    string str;
    cin >> str;
    
    set<char> mySet;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'M' || str[i] == 'O' || str[i] == 'B' || str[i] == 'I' || str[i] == 'S') {
            mySet.insert(str[i]);
        }
    }
    
    if (mySet.size() == 5) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}