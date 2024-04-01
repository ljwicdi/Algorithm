import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    public static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static class PointComparator implements Comparator<Point> {
        @Override
        public int compare(Point a, Point b) {

            if (a.x != b.x) {
                return a.x - b.x;
            }

            return a.y - b.y;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            Point p = new Point(x, y);
            points[i] = p;
        }


        Arrays.sort(points, new PointComparator());


        for (Point p : points) {
            System.out.println(p.x + " " + p.y);
        }
    }
}
