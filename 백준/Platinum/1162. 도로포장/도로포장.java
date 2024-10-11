import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Node implements Comparable<Node> {
        int fir;
        long sec;
        int third;

        public Node(int a, long b, int c) {
            fir = a;
            sec = b;
            third = c;
        }

        public int compareTo(Node a) {
            return Long.compare(sec, a.sec);
        }
    }

    static final long INF = Long.MAX_VALUE;
    static int n, m, k;
    static long[][] dist;
    static List<Node>[] adj;

    static void dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i = 0; i <= k; i++)
            Arrays.fill(dist[i], INF);
        
        pq.offer(new Node(1, 0, 0));
        dist[0][1] = 0;

        while(!pq.isEmpty()) {
            Node cnode = pq.poll();
            int here = cnode.fir;
            long cost = cnode.sec;
            int cnt = cnode.third;

            if(dist[cnt][here] < cost) continue;

            for(Node i : adj[here]) {
                int next = i.fir;
                if(cnt < k && dist[cnt + 1][next] > cost) {
                    dist[cnt + 1][next] = cost;
                    pq.offer(new Node(next, cost, cnt + 1));
                }
                long ncost = cost + i.sec;
                if(dist[cnt][next] > ncost) {
                    dist[cnt][next] = ncost;
                    pq.offer(new Node(next, ncost, cnt));
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
        k = Integer.parseInt(input[2]);
        dist = new long[k + 1][n + 1];

        adj = new List[n + 1];
        for(int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            adj[src].add(new Node(dst, cost, 0));
            adj[dst].add(new Node(src, cost, 0));
        }

        dijkstra();
        
        long res = INF;
        for(int i = 0; i <= k; i++)
            res = Math.min(res, dist[i][n]);

        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
