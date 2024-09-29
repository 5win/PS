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

        int[] X = new int[1001];
        int maxH = 0;
        int maxidx = 0;
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if(maxH < y) {
                maxH = y;
                maxidx = x;
            }
            X[x] = y;
        }

        int sum = 0;
        int curH = 0;
        for(int i = 0; i < maxidx; i++) {
            curH = Math.max(curH, X[i]);
            sum += curH;
        }

        curH = 0;
        for(int i = 1000; i >= maxidx; i--) {
            curH = Math.max(curH, X[i]);
            sum += curH;
        }

        System.out.println(sum);
    }
}
