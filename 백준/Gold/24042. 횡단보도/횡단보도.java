import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir;
        long sec;
        public Pair(int a, long b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Pair p) {
            return (int) (sec - p.sec);
        }
    }

    static int n, m;
    static List<Pair>[] adj;
    static long[] dist;

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        pq.offer(new Pair(0, 0));

        while(!pq.isEmpty()) {
            Pair here = pq.peek();
            pq.poll();

            int node = here.fir;
            long cost = here.sec;
            if(dist[node] < cost) continue;

            for(int i = 0; i < adj[node].size(); i++) {
                int next = adj[node].get(i).fir;
                long nextCost = adj[node].get(i).sec;
                if(cost % m >= nextCost) {
                    long sum = (cost / m + 1) * m + nextCost;
                    if(dist[next] < sum) continue;
                    dist[next] = sum;
                    pq.offer(new Pair(next, sum));
                } else {
                    long sum = (cost / m) * m + nextCost;
                    if(dist[next] < sum) continue;
                    dist[next] = sum;
                    pq.offer(new Pair(next, sum));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        dist = new long[n];
        adj = new List[n];
        for(int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            src--; dst--;
            adj[src].add(new Pair(dst, i + 1));
            adj[dst].add(new Pair(src, i + 1));
        }

        dijkstra();
        bw.write(dist[n - 1] + "\n");

        bw.flush();
        bw.close();
    }
}
