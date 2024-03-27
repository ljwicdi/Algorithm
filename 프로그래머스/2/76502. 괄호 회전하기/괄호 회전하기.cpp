#include <string>
#include <vector>
#include <deque>
using namespace std;

bool check(deque<char> & dq) {
    vector<char> v;
    vector<char> test(dq.begin(), dq.end());
    if (test[0] == ')' || test[0] == ']' || test[0] == '}') {
        return false;
    }
    v.push_back(test[0]);
    for (int i = 1; i < test.size(); i++) {
        if (v.size() == 0) {
            if (test[i] == ')' || test[i] == ']' || test[i] == '}') {
                return false;
            } else {
                v.push_back(test[i]);
                continue;
            }
        }
        char tail = v.back();
        if (tail == '(') {
            if (test[i] == ')') {
                v.pop_back();
            } else {
                v.push_back(test[i]);
            }
        } else if (tail == '[') {
            if (test[i] == ']') {
                v.pop_back();
            } else {
                v.push_back(test[i]);
            }
        } else if (tail == '{') {
            if (test[i] == '}') {
                v.pop_back();
            } else {
                v.push_back(test[i]);
            }
        } else {
            v.push_back(test[i]);
        }
    }
    
    if (v.size() == 0) {
        return true;
    } else {
        return false;
    }
}

int solution(string s) {
    int answer = 0;
    deque<char> dq;
    for (int i = 0; i < s.length(); i++) {
        dq.push_back(s[i]);
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s.length() == 1) {
            break;
        }
        if (check(dq)) {
            answer++;
        }
        
        char f = dq.front();
        dq.pop_front();
        dq.push_back(f);
    }
    return answer;
}