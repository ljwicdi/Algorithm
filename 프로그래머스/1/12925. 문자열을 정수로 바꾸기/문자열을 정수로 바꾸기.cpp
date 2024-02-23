#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string newStr;
    int chk = 0;
    if (s[0] == '+') {
        for (int i = 1; i < s.length(); i++) {
            newStr += s[i];
        }
        chk = 1;
    } else if (s[0] == '-') {
        for (int i = 1; i < s.length(); i++) {
            newStr += s[i];
        }
        chk = -1;
    } else {
        for (int i = 0; i < s.length(); i++) {
            newStr += s[i];
        }
        chk = 1;
    }

    int answer = 0;
    answer = stoi(newStr);
    
    if (chk == -1) {
        answer = answer * -1;
    }
    return answer;
}