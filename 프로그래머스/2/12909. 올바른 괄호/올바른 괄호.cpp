#include<string>
#include <queue>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    queue<char> q;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            q.push(s[i]);
        } else {
            if (q.size() != 0) {
                q.pop();
            } else {
                answer = false;
                break;
            }
        }
    }
    if (q.size() != 0) 
        answer = false;
    return answer;
}