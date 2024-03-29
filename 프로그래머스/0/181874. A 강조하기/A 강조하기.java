class Solution {
    public String solution(String myString) {
        String answer = "";
        answer = myString.replace("a", "A");
        for (int i = 0; i < answer.length(); i++) {
            char c = answer.charAt(i);
            int temp;
            if (c != 'A' && c >= 65 && c <= 90) {
                temp = c + 32;
                char[] chars = answer.toCharArray();
                chars[i] = (char)temp;
                answer = String.valueOf(chars);
            }
            
        }
        return answer;
    }
}