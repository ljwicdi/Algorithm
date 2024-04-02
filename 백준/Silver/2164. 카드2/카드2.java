
import java.util.*;

public class Main {



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // 1 ~ n
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            queue.add(i);
        }

        // 큐에 남는 카드가 하나일 때 까지 반복
        while (queue.size() > 1) {
            // 제일 위에 있는 카드를 바닥에 버림
            queue.poll();

            // 버렸는데도 남아있다면 제일 위에 있는 카드를 제일 밑으로 보냄
            if (queue.size() > 1) {
                queue.add(queue.peek());
                queue.poll();
            }
        }

        System.out.println(queue.peek());
    }
}
