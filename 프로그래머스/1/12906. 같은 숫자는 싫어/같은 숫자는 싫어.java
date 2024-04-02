import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        ArrayList<Integer> temp= new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.valueOf(arr[0]));
        temp.add(Integer.valueOf(arr[0]));
        
        for (int i = 1; i < arr.length; i++) {
            if (!stack.empty()) {
                if (stack.peek() != arr[i]) {
                    stack.push(Integer.valueOf(arr[i]));
                    temp.add(Integer.valueOf(arr[i]));
                }
            } 
        }
        
        int[] answer = new int[temp.size()];
        
        for (int i = 0; i < temp.size(); i++) {
            answer[i] = temp.get(i);
        }
        return answer;
    }
}