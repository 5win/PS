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

    static int n, m, k;
    static List<Pair>[] adj;
    static long[] dist;
    static final long INF = Long.MAX_VALUE;

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(0, 0));
        Arrays.fill(dist, INF);
        dist[0] = 0; 

        while(!pq.isEmpty()) {
            Pair cNode = pq.poll();
            int here = cNode.fir;
            long cost = cNode.sec;

            if(dist[here] < cost) continue;

            for(Pair i : adj[here]) {
                int next = i.fir;
                long nextCost = i.sec + cost;
                if(dist[next] <= nextCost) continue;
                dist[next] = nextCost;
                pq.offer(new Pair(next, nextCost));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        k = Integer.parseInt(input[2]);

        dist = new long[n + 1];
        adj = new List[n + 1];
        for(int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            adj[dst].add(new Pair(src, cost));
        }
        input = br.readLine().split(" ");
        for(int i = 0; i < k; i++) {
            int dst = Integer.parseInt(input[i]);
            adj[0].add(new Pair(dst, 0));
        }

        dijkstra();

        int idx = 1;
        long res = dist[1];
        for(int i = 2; i <= n; i++) {
            if(dist[i] == INF) continue;
            if(res < dist[i]) {
                idx = i;
                res = dist[i];
            }
        }
        bw.write(idx + "\n");
        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
