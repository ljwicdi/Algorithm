#include <iostream>
#include <string>
using namespace std;
int main() {
    
    int testCase;
    cin >> testCase;
    cin.ignore();
    string str;
    for (int i = 0; i < testCase; i++) {
        getline(cin, str);
        
        int sum = 0;
        int index = 0;
        
        bool flag = false;
        while (index <= str.length() - 1) {
            string temp = "";
            while (str[index] != ' ') {
                temp += str[index];
                index++;
                if (index == str.length()) {
                    sum = sum + stoi(temp);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
            sum += stoi(temp);
            index++;
        }
        
        cout << sum << "\n";
    }
    return 0;
}
