import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int compareTo(Pair p) {
            return x - p.x;
        }
    }


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        List<Pair> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            list.add(new Pair(x, y));
        }
        Collections.sort(list);

        List<Pair> left = new ArrayList<>();
        List<Pair> right = new ArrayList<>();

        left.add(list.get(0));
        for(int i = 1; i < n; i++) {
            if(left.get(left.size() - 1).y < list.get(i).y) {
                left.add(list.get(i));
            }
        }

        right.add(list.get(n - 1));
        for(int i = n - 2; i >= 0; i--) {
            if(right.get(right.size() - 1).y < list.get(i).y) {
                right.add(list.get(i));
            }
        }

        int sum = 0;
        for(int i = 0; i < left.size() - 1; i++) {
            sum += (left.get(i + 1).x - left.get(i).x) * left.get(i).y;
        }

        for(int i = 0; i < right.size() - 1; i++) {
            sum += (right.get(i).x - right.get(i + 1).x) * right.get(i).y;
        }

        sum += (right.get(right.size() - 1).x + 1 - left.get(left.size() - 1).x) * left.get(left.size() - 1).y;
        System.out.println(sum);
    }
}
