import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Pair p) {
            return sec - p.sec;
        }
    }

    static int n, m, x;
    static int[][] adj = new int[1001][1001];
    static int[][] radj = new int[1001][1001];

    static int[] dijkstra(int[][] edge) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int[] dist = new int[1001];
        Arrays.fill(dist, Integer.MAX_VALUE);

        dist[x] = 0;
        pq.offer(new Pair(x, 0));

        while(!pq.isEmpty()) {
            Pair here = pq.peek();
            pq.poll();

            if(dist[here.fir] < here.sec) continue;

            for(int i = 1; i <= n; i++) {
                if(edge[here.fir][i] == 0) continue;
                int next = i;
                int cost = here.sec + edge[here.fir][i];
                if(dist[next] > cost) {
                    dist[next] = cost;
                    pq.offer(new Pair(next, cost));
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        x = Integer.parseInt(input[2]);
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            adj[src][dst] = cost;
            radj[dst][src] = cost;
        }

        int[] go = dijkstra(radj);        
        int[] back = dijkstra(adj);

        int max = 0;
        for(int i = 1; i <= n; i++)
            max = Math.max(max, go[i] + back[i]);

        bw.write(String.valueOf(max));

        bw.flush();
        bw.close();
    }
}
