import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stack = new Stack<>();
        
        stack.push(s.charAt(0));
        
        for (int i = 1; i < s.length(); i++) {
            if (stack.empty()) {
                if (s.charAt(i) == ')') {
                    answer = false;
                    break;
                }
                stack.push(s.charAt(i));
            } else {
                if (s.charAt(i) == '(') {
                    stack.push(s.charAt(i));
                } else {
                    if (stack.peek() == '(') {
                        stack.pop();
                    } else {
                        stack.push(s.charAt(i));
                    }
                }
            }
        }
        
        if (stack.size() != 0) {
            answer = false;
        }
        return answer;
    }
}