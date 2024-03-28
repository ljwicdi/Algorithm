class Solution {
    public int solution(int price) {
        double answer = 0;
        double percent = 0.0;
        if (price >= 500000) {
            percent = 0.2;
        } else if (price >= 300000) {
            percent = 0.1;
        } else if (price >= 100000) {
            percent = 0.05;
        } else {
            percent = 0;
        }
        
        double temp = price * percent;
        answer = (double)price - temp;
        return (int)answer;
    }
}