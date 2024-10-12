import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Node implements Comparable<Node> {
        int fir, sec;
        public Node(int a, int b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Node o) {
            return sec - o.sec;
        }
    }

    static int n, m, k;
    static List<Node>[] adj;
    static PriorityQueue<Integer>[] distpq;

    static void dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0));

        while(!pq.isEmpty()) {
            Node cnode = pq.poll();
            int here = cnode.fir;
            int cost = cnode.sec;

            for(Node i : adj[here]) {
                int next = i.fir;
                int nc = cost + i.sec;
                if(distpq[next].size() == k) {
                    if(distpq[next].peek() > nc) {
                        distpq[next].poll();
                        distpq[next].offer(nc);
                        pq.offer(new Node(next, nc));
                    }
                } else {
                    distpq[next].offer(nc);
                    pq.offer(new Node(next, nc));
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

        adj = new List[n];
        distpq = new PriorityQueue[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
            distpq[i] = new PriorityQueue<>(Collections.reverseOrder());
        }

        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;

            adj[src].add(new Node(dst, cost));
        }
        distpq[0].offer(0);
        dijkstra();

        for(int i = 0; i < n; i++) {
            while(distpq[i].size() > k) distpq[i].poll();

            if(distpq[i].size() < k) {
                bw.write("-1\n");
            } else {
                bw.write(distpq[i].peek() + "\n");
            }
        }


        bw.flush();
        bw.close();
    }
}
