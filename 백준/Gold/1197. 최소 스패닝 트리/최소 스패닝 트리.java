import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;


public class Main {

    static final int INF = 1987654321;


    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int v = sc.nextInt();
        int e = sc.nextInt();

        List<int[]>[] adj = new ArrayList[v];
        for(int i = 0; i < v; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < e; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();

            adj[a].add(new int[]{b, c});
            adj[b].add(new int[]{a, c});
        }


        // prim
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        boolean[] visited = new boolean[v];

        // init pq
        visited[0] = true;
        for(int[] next : adj[0]) {
            pq.offer(next);
        }

        int sum = 0;
        while(!pq.isEmpty()) {
            int[] here = pq.poll();

            int b = here[0];
            int cost = here[1];

            if(visited[b]) continue;
            visited[b] = true;
            sum += cost;

            for(int[] next : adj[b]) {
                if(visited[next[0]]) continue;
                pq.offer(next);
            }
        }

        System.out.println(sum);
    }
}
