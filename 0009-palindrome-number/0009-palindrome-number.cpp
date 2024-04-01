class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        // 만약 x가 0인 경우 
        if (x == 0) {
            return true;
        }
        vector<int> temp;
        bool result = true;
        while (x != 0) {
            temp.push_back(x % 10);
            x = x / 10;
        }
        
        int left = 0;
        int right = temp.size() - 1;
        if (temp.size() % 2 == 0) {
            while (1) {
                if (temp[left] != temp[right]) {
                    result = false;
                    break;
                }
                left++;
                right--;
                if (left >= temp.size() / 2) {
                    break;
                }
            }
        } else {
            while (1) {
                if (temp[left] != temp[right]) {
                    result = false;
                    break;
                }
                left++;
                right--;
                if (left >= temp.size() / 2 + 1) {
                    break;
                }
            }
        }
        return result;
    }
    
};