import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {
    
    static int n, m, v;
    static List<Integer>[] adj = new List[1001];
    static boolean[] visited = new boolean[1001];

    static void dfs(int here) {
        System.out.print(here + " ");

        Collections.sort(adj[here]);
        for(int i = 0; i < adj[here].size(); i++) {
            int next = adj[here].get(i);
            if(visited[next]) continue;
            visited[next] = true;
            dfs(next);
        }
    }

    static void bfs() {
        Queue<Integer> q = new LinkedList<>();
        visited[v] = true;
        q.offer(v);

        while(!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            System.out.print(here + " ");

            Collections.sort(adj[here]);
            for(int i = 0; i < adj[here].size(); i++) {
                int next = adj[here].get(i);
                if(visited[next]) continue;
                visited[next] = true;
                q.offer(next);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();
        for(int i = 0; i < 1001; i++) 
            adj[i] = new ArrayList<>();
        
        for(int j = 0; j < m; j++) {
            int s = sc.nextInt();
            int e = sc.nextInt();
            adj[s].add(e);
            adj[e].add(s);
        }

        visited[v] = true;
        dfs(v);
        System.out.println();
        Arrays.fill(visited, false);
        bfs();
    }
}
