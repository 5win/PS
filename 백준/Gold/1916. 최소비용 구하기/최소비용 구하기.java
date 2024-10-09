import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir;
        int sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }

        public int compareTo(Pair p) {
            return sec - p.sec;
        }
    }

    static final int INF = Integer.MAX_VALUE;
    static int n, m;
    static List<Pair>[] adj;

    static int[] dijkstra(int src) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int[] dist = new int[1001];
        pq.offer(new Pair(src, 0));
        Arrays.fill(dist, INF);
        dist[src] = 0;

        while(!pq.isEmpty()) {
            Pair here = pq.poll();

            int node = here.fir;
            int cost = here.sec;
            if(dist[node] < cost) continue;

            for(int i = 0; i < adj[node].size(); i++) {
                int next = adj[node].get(i).fir;
                int nextCost = cost + adj[node].get(i).sec;
                if(dist[next] <= nextCost) continue;
                dist[next] = nextCost;
                pq.offer(new Pair(next, nextCost));
            }
        }
        return dist;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        adj = new List[n];
        for(int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        String[] input;
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;
            adj[src].add(new Pair(dst, cost));
        }
        input = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        A--; B--;

        int[] dist = dijkstra(A);
        bw.write(dist[B] + "\n");

        bw.flush();
        bw.close();
    }
}
