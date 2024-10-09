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

    static final int INF = Integer.MAX_VALUE / 3;
    static int n, e;
    static List<Pair>[] adj;

    static int[] dijkstra(int src) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int[] dist = new int[801];
        pq.offer(new Pair(src, 0));
        Arrays.fill(dist, INF);
        dist[src] = 0;

        while(!pq.isEmpty()) {
            Pair here = pq.peek();
            pq.poll();

            int node = here.fir;
            int cost = here.sec;
            if(dist[node] < cost) continue;
            for(int i = 0; i < adj[node].size(); i++) {
                int next = adj[node].get(i).fir;
                int nextCost = cost + adj[node].get(i).sec;
                if(dist[next] < nextCost) continue;
                dist[next] = nextCost;
                pq.offer(new Pair(next, nextCost));
            }
        }
        return dist;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        e = Integer.parseInt(input[1]);
        adj = new List[n];
        for(int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < e; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;
            adj[src].add(new Pair(dst, cost));
            adj[dst].add(new Pair(src, cost));
        }
        input = br.readLine().split(" ");
        int v1 = Integer.parseInt(input[0]);
        int v2 = Integer.parseInt(input[1]);
        v1--; v2--;

        int[] dist1 = dijkstra(0);
        int[] dist2 = dijkstra(v1);
        int[] dist3 = dijkstra(v2);

        int res1 = dist1[v1] + dist2[v2] + dist3[n - 1];
        int res2 = dist1[v2] + dist3[v1] + dist2[n - 1];
        if(res1 >= INF && res2 >= INF)
            bw.write("-1\n");
        else
            bw.write(Math.min(res1, res2) + "\n");

        bw.flush();
        bw.close();
    }
}
