import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir;
        long sec;
        int third, prevW;
        public Pair(int a, long b, int w) {
            fir = a;
            sec = b;
            prevW = w;
        }

        public Pair(int a, long b, int c, int w) {
            fir = a;
            sec = b;
            third = c;
            prevW = w;
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
    static int[] w1, w2;

    static long[] dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        long[] dist = new long[n + 1];
        pq.offer(new Pair(A, 0, 0));
        Arrays.fill(dist, INF);
        dist[A] = 0;

        while(!pq.isEmpty()) {
            Pair cNode = pq.poll();
            int here = cNode.fir;
            long cost = cNode.sec;
            int prevW = cNode.prevW;

            if(dist[here] < cost) continue;
            for(Pair i : adj[here]) {
                int next = i.fir;
                long nextCost = cost + i.sec;
                if(dist[next] <= nextCost) continue;

                int maxW = Math.max(prevW, i.prevW);
                dist[next] = nextCost;
                w1[next] = maxW;
                pq.offer(new Pair(next, nextCost, maxW));
            }
        }
        return dist;
    }

    static long[] mst() {
        Comparator<Pair> cmp = (a, b) -> a.third - b.third;
        PriorityQueue<Pair> pq = new PriorityQueue<>(cmp);
        long[] dist = new long[n + 1];
        Arrays.fill(dist, INF);
        pq.offer(new Pair(A, 0, 0));
        // dist[A] = 0;

        while(!pq.isEmpty()) {
            Pair cNode = pq.poll();
            int here = cNode.fir;
            long cost = cNode.sec;
            int weight = cNode.third;
            
            if(dist[here] != INF) continue;
            dist[here] = cost;
            w2[here] = Math.max(weight, cNode.prevW);

            for(Pair i : adj[here]) {
                int next = i.fir;
                long nc = cost + i.sec;
                int w = i.third;
                if(dist[next] != INF) continue;
                pq.offer(new Pair(next, nc, w, i.prevW));
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
            adj[src].add(new Pair(dst, cost, cost));
        }

        w1 = new int[n + 1];
        w2 = new int[n + 1];
        long[] d1 = dijkstra();
        long[] d2 = mst();

        if(d2[B] <= C) {
            // bw.write(d2[B] + "\n");
            bw.write(w2[B] + "\n");
        } else if(d1[B] <= C) {
            bw.write(w1[B] + "\n");
        } else {
            bw.write("-1\n");
        }


        bw.flush();
        bw.close();
    }
}
