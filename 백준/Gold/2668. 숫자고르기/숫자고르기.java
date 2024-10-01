import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static List<Integer>[] adj = new List[101];
    static boolean[] visited = new boolean[101];
    static Set<Integer> set = new TreeSet<>();

    static void dfs(int here, List<Integer> route) {

        for(int next : adj[here]) {
            if(visited[next]) {
                boolean start = false;
                for(int node : route) {
                    if(node == next) start = true;
                    if(start) set.add(node);
                }
                continue;
            }
            visited[next] = true;
            route.add(next);
            dfs(next, route);
            route.remove(route.size() - 1);
            visited[next] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i = 0; i < 101; i++) adj[i] = new ArrayList<>();

        n = Integer.parseInt(br.readLine());
        for(int i = 1; i <= n; i++) {
            int dst = Integer.parseInt(br.readLine());
            adj[i].add(dst);
        }

        List<Integer> route = new ArrayList<>();
        for(int i = 1; i <= n; i++) {
            visited[i] = true;
            route.add(i);
            dfs(i, route);
            route.remove(route.size() - 1);
            visited[i] = false;
        }
        bw.write(String.valueOf(set.size()) + "\n");
        for(int i : set) {
            bw.write(String.valueOf(i) + "\n");
        }

        bw.flush();
        bw.close();
    }
}
