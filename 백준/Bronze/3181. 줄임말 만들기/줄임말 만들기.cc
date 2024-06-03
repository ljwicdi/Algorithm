
#include <iostream>
#include <sstream>
#include <set>
#include <cctype>
using namespace std;
int main() {
    // 'i', 'pa', 'te', 'ni', 'niti', 'a', 'ali', 'nego', 'no', 'ili'.
    set<string> mySet = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};

    string str;
    getline(cin, str);
    
    string token;
    istringstream iss(str);
    
    int executionCnt = 0;
    while (getline(iss, token, ' ')) {
        
        if (mySet.find(token) != mySet.end()) {
            if (executionCnt == 0) {
                cout << (char)toupper(token[0]);
            } 
            
        } else {
            cout << (char)toupper(token[0]);
        }
        
        executionCnt++;
    }

    return 0;
}
