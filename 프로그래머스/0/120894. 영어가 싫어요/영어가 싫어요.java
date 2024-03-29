import java.util.HashMap;

class Solution {
    public long solution(String numbers) {
        String answer = "";
        
        HashMap<String, Character> m = new HashMap<String, Character>();
        m.put("zero", '0'); m.put("one", '1'); m.put("two", '2'); m.put("three", '3');
        m.put("four", '4'); m.put("five", '5'); m.put("six", '6'); m.put("seven", '7');
        m.put("eight", '8'); m.put("nine", '9');
        
        
        // 3, 4, 5
        int index = 0;
        while(true) {
            if (index >= numbers.length()) {
                break;
            }
            String temp = "";
            // 3글자 체킹 (최소 3글자는 남아있음)
            for (int i = index; i < index + 3; i++) {
                temp += numbers.charAt(i);
            }
            if (m.containsKey(temp)) {
                answer += m.get(temp);
                index += 3;
                continue;
            } 
            temp = "";
            for (int i = index; i < index + 4; i++) {
                temp += numbers.charAt(i);
            }
            if (m.containsKey(temp)) {
                answer += m.get(temp);
                index += 4;
                continue;
            }
            temp = "";
            for (int i = index; i < index + 5; i++) {
                temp += numbers.charAt(i);
            }
            if (m.containsKey(temp)) {
                answer += m.get(temp);
                index += 5;
                continue;
            }
            
            
        }
        long answer2 = Long.parseLong(answer);
        return answer2;
    }
}