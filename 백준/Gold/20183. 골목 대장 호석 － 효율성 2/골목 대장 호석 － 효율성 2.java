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

        @Override
        public int compareTo(Pair p) {
            return Long.compare(sec, p.sec);
        }
    }

    static final long INF = Long.MAX_VALUE;
    static int n, m, A, B;
    static long C;
    static List<Pair>[] adj;

    static long[] dijkstra(int limit) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        long[] dist = new long[n + 1];
        pq.offer(new Pair(A, 0));
        Arrays.fill(dist, INF);
        dist[A] = 0;

        while(!pq.isEmpty()) {
            Pair cNode = pq.poll();
            int here = cNode.fir;
            long cost = cNode.sec;

            if(dist[here] < cost) continue;
            for(Pair i : adj[here]) {
                int next = i.fir;
                long nextCost = cost + i.sec;
                if(dist[next] <= nextCost || i.sec > limit) continue;
                if(nextCost > C) continue;

                dist[next] = nextCost;
                pq.offer(new Pair(next, nextCost));
            }
        }
        return dist;
    }

    static int binarySearch() {
        int s = 0, e = (int) 1e9;

        while(s + 1 < e) {
            int mid = (s + e) / 2;
            long[] d = dijkstra(mid);
            if(d[B] <= C) {
                e = mid;
            } else {
                s = mid;
            }
        }
        return e;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        A = Integer.parseInt(input[2]);
        B = Integer.parseInt(input[3]);
        C = Long.parseLong(input[4]);

        adj = new List[n + 1];
        for(int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();

        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            adj[src].add(new Pair(dst, cost));
            adj[dst].add(new Pair(src, cost));
        }

        int res = binarySearch();

        if(res != (int) 1e9) {
            bw.write(res + "\n");
        } else {
            bw.write("-1\n");
        }


        bw.flush();
        bw.close();
    }
}
