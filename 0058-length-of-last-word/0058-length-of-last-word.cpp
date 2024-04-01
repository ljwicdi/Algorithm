
class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";
        int index = s.length() - 1;
        int chk = 0;
        while (1) {
            if (index < 0) break; 
            if (s[index] == ' ') {
                if (chk != 0) 
                    break;
                index--;
                continue;
            }
            chk++;
            index--;
        }
        index++;
        for (int i = index; i < s.length(); i++) {
            if (s[i] == ' ') break;
            temp += s[i];
        }
        return temp.length();
    }
};