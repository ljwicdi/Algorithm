import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
class Solution {
    public String solution(String s) {
        String answer = "";
        HashMap<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (m.containsKey(c)) {
                m.put(c, m.get(c) + 1);
            } else {
                m.put(c, 1);
            }
        }
        
       ArrayList<Character> arr = new ArrayList<>();
        for (Character c : m.keySet()) {
            if (m.get(c) == 1) {
                arr.add(c);
            }
        }
        Collections.sort(arr);
        for (Character c : arr) {
            answer += c;
        }
        return answer;
    }
}