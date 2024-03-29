class Solution {
    public String solution(String my_string, int s, int e) {
        String answer = "";
        String newStr = "";
        for (int i = e; i >= s; i--) {
            newStr = newStr + my_string.charAt(i);
        }
        
        for (int i = 0; i < s; i++) {
            answer = answer + my_string.charAt(i);
        }
        answer = answer + newStr;
        for (int i = e + 1; i < my_string.length(); i++) {
            answer = answer + my_string.charAt(i);
        }
        return answer;
    }
}