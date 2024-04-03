import java.util.Stack;

class Solution {
    public int solution(int[] ingredient) {
        if (ingredient.length < 4) return 0;
        
        int answer = 0; 
        Stack<Integer> stack = new Stack<>(); 
        int cnt = 0;
        
        for (int i = 0; i < ingredient.length; i++) {
            stack.push(ingredient[i]);
            if (stack.size() >= 4) {  
                if (stack.get(stack.size() - 4) == 1 && stack.get(stack.size() - 3) == 2
                        && stack.get(stack.size() - 2) == 3 && stack.peek() == 1) {
                    for (int j = 0; j < 4; j++) {
                        stack.pop();
                    }
                    answer++;
                }
            }
        }
        
        return answer;
    }
}