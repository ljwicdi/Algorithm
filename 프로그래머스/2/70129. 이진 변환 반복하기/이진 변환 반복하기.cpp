#include <string>
#include <vector>
#include <string>
using namespace std;

string change(int s) {
    string result = "";
    string t = "";
    int temp = s;
    while (temp != 0) {
        t += to_string(temp % 2);
        temp = temp / 2;
    }
    
    for (int i = t.size() - 1; i >= 0; i--) {
        result += t[i];
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int changeCnt = 0, zeroCnt = 0;
    
    string temp = s;
    while (1) {
        if (temp == "1") {
            break;
        }
        changeCnt++;
        int oneCnt = 0;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '1') {
                oneCnt++;
            }
            
        }
        zeroCnt += (temp.length() - oneCnt);
        temp = change(oneCnt);
        
    }
    answer.push_back(changeCnt);
    answer.push_back(zeroCnt);
    return answer;
}