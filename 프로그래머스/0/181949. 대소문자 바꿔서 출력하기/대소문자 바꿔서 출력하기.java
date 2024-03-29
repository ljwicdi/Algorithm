import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String answer = "";
        for (int i = 0; i < a.length(); i++) {
            char c = a.charAt(i);
            int temp;
            if (c >= 97 && c <= 122) {
                temp = c - 32;
            } else {
                temp = c + 32;
            }
            answer = answer + String.valueOf((char)temp);
        }
        System.out.println(answer);
    }
}