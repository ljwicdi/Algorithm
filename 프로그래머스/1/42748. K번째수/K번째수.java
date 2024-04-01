import java.util.ArrayList;
import java.util.Collections;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int i = 0; i < commands.length; i++) {
            int startIndex = commands[i][0] - 1;
            int endIndex = commands[i][1] - 1;
            ArrayList<Integer> arr = new ArrayList<>();
            for (int j = startIndex; j <= endIndex; j++) {
                arr.add(array[j]);
            }
            Collections.sort(arr);
            
            answer[i] = arr.get(commands[i][2] - 1);
        }
        return answer;
    }
}