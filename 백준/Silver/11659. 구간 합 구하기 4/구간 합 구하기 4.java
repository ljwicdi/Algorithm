

import java.util.Arrays;
import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int[] arr = new int[n + 1];
        arr[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            arr[i] = scanner.nextInt();
        }
        int[] sum = new int[n + 1];
        sum[0] = 0;
        sum[1] = arr[1];
        for (int i = 2; i < n + 1; i++) {
            sum[i] = sum[i - 1] + arr[i];
        }

        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            System.out.println(sum[b] - sum[a - 1]);
        }

    }

}