import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    static int n, k;
    static List<Integer>[] adj;

    static boolean[] bfs() {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n + 1];
        visited[1] = true;
        q.offer(1);

        while(!q.isEmpty()) {
            int here = q.poll();

            for(int next : adj[here]) {
                if(visited[next]) continue;
                visited[next] = true;
                q.offer(next);
            }
        }

        return visited;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = sc.nextInt();
        k = sc.nextInt();
        adj = new ArrayList[n + 1];
        for(int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        //edge
        for(int i = 0; i < k; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }

        boolean[] visited = bfs();
        int cnt = 0;
        for(int i = 2; i <= n; i++) {
            if(visited[i]) cnt++;
        }
        System.out.println(cnt);
    }
}
