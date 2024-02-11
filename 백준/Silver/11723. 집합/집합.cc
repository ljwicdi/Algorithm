
#include <iostream>
#include <set>
using namespace std;



int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    set<int> mySet;
    
    int M;
    cin >> M;
    cin.ignore();
    string str;

    for (int i = 0; i < M; i++) {
        getline(cin, str);
        
        if (str == "all") {
            for (int j = 1; j <= 20; j++) {
                if (mySet.find(j) == mySet.end()) {
                    mySet.insert(j);
                }
            }
            continue;
        }
        
        if (str == "empty") {
            mySet.clear();
            continue;
        }
        
        int chk = 0;
        int a;
        if (str[str.length() - 2] == '1' || str[str.length() - 2] == '2') {
            a = 10 * (str[str.length() - 2] - '0') + (str[str.length() - 1] - '0');
            chk = 1;
        } else {
            a = str[str.length() - 1] - '0';
        }
        
        string order = "";
        
        if (chk == 0) {
            for (int j = 0; j < str.length() - 2; j++) {
                order = order + str[j];
            }
        } else {
            for (int j = 0; j < str.length() - 3; j++) {
                order = order + str[j];
            }
        }
        
       
        if (order == "add") {
            if (mySet.find(a) == mySet.end()) {
                mySet.insert(a);
            }
        } else if (order == "remove") {
            if (mySet.find(a) != mySet.end()) {
                mySet.erase(a);
            }
        } else if (order == "check") {
          
         
            if (mySet.find(a) == mySet.end()) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else if (order == "toggle") {
            if (mySet.find(a) == mySet.end()) {
                mySet.insert(a);
            } else {
                mySet.erase(a);
            }
        }
        
    }
    
    
    return 0;
}
