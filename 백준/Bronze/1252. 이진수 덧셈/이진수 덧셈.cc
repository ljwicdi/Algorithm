
#include <iostream>
using namespace std;

string subZero(string str) {
    
    int oneIndex = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            oneIndex = i; 
            break;
        }
    }
    
    string newStr = "";
    for (int i = oneIndex; i < str.length(); i++) {
        newStr += str[i];
    }
    
    return newStr;
}

pair<string, string> constantLength(string a, string b) {
    
    string temp = "";
    if (a.length() < b.length()) {
        for (int i = 0; i < b.length() - a.length(); i++) {
            temp += '0';
        }
        a = temp + a;
    } else {
        for (int i = 0; i < a.length() - b.length(); i++) {
            temp += '0';
        }
        b = temp + b;
    }
    
    return make_pair(a, b);
}

string sol(pair<string, string> strs) {
    
    string a = strs.first;
    string b = strs.second;
    
    bool carry = false; 
    string result = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        
        if (carry) {
            if (a[i] == '0') a[i] = '1';
            else if (a[i] == '1') a[i] = '2';
            else if (a[i] == '2') a[i] = '3';
            carry = false;
        }
        
        if ((a[i] - '0') + (b[i] - '0') == 0) {
            result += '0';
        } else if ((a[i] - '0') + (b[i] - '0') == 1) {
            result += '1';
        } else if ((a[i] - '0') + (b[i] - '0') == 2) {
            result += '0';
            carry = true;
        } else if ((a[i] - '0') + (b[i] - '0') == 3) {
            result += '1';
            carry = true;
        }
    }
    
    if (carry) {
        result += '1';
    }
    
    string reverseResult = "";
    
    for (int i = result.length() - 1; i >= 0; i--) {
        reverseResult += result[i];
    }
    
    return reverseResult;
}

bool isOne(string str) {
    bool isOne = false;
    for (auto s : str) {
        if (s == '1') {
            isOne = true;
        }
    }
    return isOne;
}
int main() {
    
    string a, b;
    cin >> a >> b;
    
    string subA = subZero(a);
    string subB = subZero(b);
    
    pair<string, string> strs = constantLength(subA, subB);
    
    string result = sol(strs);
    
    if (!isOne(a) && !isOne(b)) {
        cout << '0';
    } else {
        cout << subZero(result); 
    }
    return 0;
}
