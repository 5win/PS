import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int s, dist;
        public Pair(int s, int d) {
            this.s = s;
            dist = d;
        }
    }

    static int n, d;
    static List<Pair>[] adj = new List[10001];

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < 10001; i++)
            adj[i] = new ArrayList<>();

        n = sc.nextInt();
        d = sc.nextInt();
        for(int i = 0; i < n; i++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            int dist = sc.nextInt();
            adj[e].add(new Pair(s, dist));
        }

        int[] cost = new int[100001];
        cost[0] = 0;
        for(int i = 1; i <= d; i++) {
            cost[i] = cost[i - 1] + 1;
            for(Pair p : adj[i]) {
                cost[i] = Math.min(cost[p.s] + p.dist, cost[i]);
            }
        }
        System.out.println(cost[d]);
    }
}
