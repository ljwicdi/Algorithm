import java.util.*;
class Solution {
    public String solution(String my_string, int n) {
        String answer = "";
        Stack<Character> stack = new Stack<>();
        for (int i = my_string.length() - 1; i > my_string.length() -1 - n; i--) {
            stack.push(my_string.charAt(i));
        }
        
        while (!stack.empty()) {
            answer += stack.pop();
        }
        return answer;
    }
}