import java.util.*;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        
        ArrayList<Queue<Integer>> arr = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            Queue<Integer> q = new LinkedList<>();
            for (int j = 0; j < board.length; j++) {
                if (board[j][i] != 0) {
                    q.offer(board[j][i]);
                }
            }
            arr.add(q);
        }
        
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < moves.length; i++) {
            Queue<Integer> q = arr.get(moves[i] - 1);
            if (q.size() == 0) continue;
            Integer catchedDoll = q.remove();
            
            if (stack.empty()) {
                stack.push(catchedDoll);
            } else {
                if (stack.peek() == catchedDoll) {
                    answer = answer + 2;
                    stack.pop();
                } else {
                    stack.push(catchedDoll);
                }
            }
            
        }
        return answer;
    }
}