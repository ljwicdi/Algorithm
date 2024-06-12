
#include <iostream>
#include <string>
using namespace std;

string solve(int value) {
    if (value % 3 == 0 && value % 5 == 0) {
        return "FizzBuzz";
    } else if (value % 3 == 0 && value % 5 != 0) {
        return "Fizz";
    } else if (value % 3 != 0 && value % 5 == 0) {
        return "Buzz";
    } else {
        return to_string(value);
    }
}

int main() {
    
    string str, result;
    int changeFocus;
    for (int i = 0; i < 3; i++) {
        cin >> str;
        if (str[0] != 'F' && str[0] != 'B') {
            changeFocus = stoi(str);
            
            if (i == 0) {
                changeFocus += 3;
            } else if (i == 1) {
                changeFocus += 2;
            } else {
                changeFocus += 1;
            }
            
            result = solve(changeFocus);
            
        }
    }
    
    cout << result;

    return 0;
}
