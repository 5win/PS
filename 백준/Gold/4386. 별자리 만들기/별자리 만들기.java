import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

class Edge {
    int dst;
    double cost;

    public Edge(int a, double b) {
        dst = a;
        cost = b;
    }
}

public class Main {

    static final int INF = 1987654321;

    static int n;
    static List<double[]> stars = new ArrayList<>();
    static List<Edge>[] adj;

    static double prim() {

        PriorityQueue<Edge> pq = new PriorityQueue<>((a, b) -> Double.compare(a.cost, b.cost));
        boolean[] visited = new boolean[n];

        visited[0] = true;
        for(Edge next : adj[0]) {
            pq.offer(next);
        }

        double sum = 0;
        while(!pq.isEmpty()) {
            Edge here = pq.poll();

            if(visited[here.dst]) continue;

            visited[here.dst] = true;
            sum += here.cost;
            for(Edge next : adj[here.dst]) {
                pq.offer(next);
            }
        }
        return sum;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            double u = sc.nextDouble();
            double v = sc.nextDouble();
            stars.add(new double[]{u, v});
        }

        adj = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        // make edge
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                double x = stars.get(i)[0] - stars.get(j)[0];
                double y = stars.get(i)[1] - stars.get(j)[1];
                double cost = Math.sqrt(x * x + y * y);
                adj[i].add(new Edge(j, cost));
                adj[j].add(new Edge(i, cost));
            }
        }

        System.out.printf("%.2f", prim());
    }
}
