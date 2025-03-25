import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;


public class Main {

    static final int INF = 1987654321;

    static int[] parent;

    static int find(int u) {
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }

    static void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return;
        parent[u] = v;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int v = sc.nextInt();
        int e = sc.nextInt();

        List<int[]> edges = new ArrayList<>();
        for(int i = 0; i < e; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();

            edges.add(new int[]{a, b, c});
        }

        // init union-find
        parent = new int[v];
        for(int i = 0; i < v; i++) {
            parent[i] = i;
        }

        // kruskal
        boolean[] selected = new boolean[e];
        Collections.sort(edges, (a, b) -> a[2] - b[2]);

        for(int i = 0; i < edges.size(); i++) {
            int[] edge = edges.get(i);
            int a = edge[0], b = edge[1];
            if(find(a) == find(b)) continue;

            merge(a, b);
            selected[i] = true;
        }

        int res = 0;
        for(int i = 0; i < edges.size(); i++) {
            if(selected[i]) {
                res += edges.get(i)[2];
            }
        }
        System.out.println(res);
    }
}
