import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        ArrayList<Integer> temp = new ArrayList<>();
        int prev = arr[0];
        temp.add(prev);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != prev) {
                temp.add(Integer.valueOf(arr[i]));
                prev = arr[i];
            }
        }
        
        int[] answer = new int[temp.size()];
        for (int i = 0; i < temp.size(); i++) {
            answer[i] = temp.get(i);
        }

        return answer;
    }
}