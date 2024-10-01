import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {
    static class Pair implements Comparable<Pair> {
        int fir, sec;
        public Pair(int f, int s) {
            fir = f;
            sec = s;
        }

        public int compareTo(Pair p) {
            return sec - p.sec;
        }
    }

    static int n, m;
    static List<Pair>[] adj = new List[50001];
    static int[] dist = new int[50001];

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;
        pq.offer(new Pair(1, 0));

        while(!pq.isEmpty()) {
            Pair here = pq.peek();
            pq.poll();

            if(dist[here.fir] < here.sec) continue;

            for(int i = 0; i < adj[here.fir].size(); i++) {
                int next = adj[here.fir].get(i).fir;
                int cost = here.sec + adj[here.fir].get(i).sec;
                if(dist[next] <= cost) continue;
                dist[next] = cost;
                pq.offer(new Pair(next, cost));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i = 0; i < 50001; i++) adj[i] = new ArrayList<>();
        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);
            int c = Integer.parseInt(input[2]);
            adj[a].add(new Pair(b, c));
            adj[b].add(new Pair(a, c));
        }
        dijkstra();
        bw.write(String.valueOf(dist[n]));

        bw.flush();
        bw.close();
    }
}
