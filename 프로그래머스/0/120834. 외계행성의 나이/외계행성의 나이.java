import java.util.HashMap;
class Solution {
    public String solution(int age) {
        String answer = "";
        HashMap<Integer, Character> m = new HashMap<Integer, Character>();
        for (int i = 0; i < 10; i++) {
            m.put(i, (char)(i + 97));
        }
        
        // 123 
        String rev = "";
        while (true) {
            int temp = age % 10;
            rev += m.get(temp);
            age = age / 10;
            if (age == 0) break;
        }
        for (int i = rev.length() - 1; i >= 0; i--) {
            answer += rev.charAt(i);
        }
        return answer;
    }
}