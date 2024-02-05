
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int count = 0;

int num[100] = {0, };

int main() {
    string str;
    cin >> str;
    
    int firstChk = 1;
    int idx = 0;
    string s = "";
    int byen = 0;
    if (str[0] == '-') {
        idx++;
        if (firstChk == 1 && str[idx] == '0') {
            while(str[idx] != '0') {
                idx++;
            }
        }
        while (str[idx] != '+' && str[idx] != '-' ) {
            s = s + to_string(str[idx] - '0');
            idx++;
        }
        num[0] = (-1) * stoi(s);
        count++;
        byen = 1;
            
    }
    if (byen == 0) {
        while (str[idx] != '+' && str[idx] != '-' && idx < str.length()) {
            if (firstChk == 1 && str[idx] == '0') {
                while(str[idx] != '0') {
                    idx++;
                }
            }
        
            firstChk = 0;
            s = s + to_string(str[idx] - '0');
            idx++;
        }
    }
    if (byen == 0) {
        num[count++] = stoi(s);
    }
    int p = 0, m = 0;
    while (1) {
    
        
        if (idx >= str.length()) {
            break;
        }
        
        string ss = "";
        if (str[idx] == '0') {
            while(str[idx] != '0') {
                idx++;
            }
        }
        
        while (str[idx] != '+' && str[idx] != '-' && idx < str.length()) {
            ss = ss + to_string(str[idx] - '0');
            idx++;
        }
        
        if (p == 1) {
            num[count++] = stoi(ss);
            p = 0;
        } else if (m == 1) {
            num[count++] = (-1) * stoi(ss);
            m = 0;
        }
        
        if (idx >= str.length()) {
            break;
        }
        
        if (str[idx] == '+') {
            p = 1;
            idx++;
            continue;
        } else if (str[idx] == '-') {
            idx++;
            m = 1;
            continue;
        }
    
    }
    
    int index = 0;
    int sum = 0;
    while (1) {
        if (num[index] < 0) {
            index++;
            while(num[index] > 0 && index <= count - 1) {
                num[index] = (-1) * num[index];
                index++;
            }
        }
        if (num[index] < 0 && index < count - 1) {
            continue;
        }
        index++;
        if (index >= count) {
            break;
        }
    } 
    
    for (int i = 0; i < count; i++) {
        sum = sum + num[i];
    }
    
    cout << sum;
    return 0;
}
