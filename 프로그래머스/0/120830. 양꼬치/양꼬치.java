class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        int bonus = n / 10;
        answer = 12000 * n + 2000 * (k - bonus);
        return answer;
    }
}