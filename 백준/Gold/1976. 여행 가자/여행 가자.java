import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static int[][] adj = new int[201][201];
    static int[] parent = new int[201];

    static int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    static void merge(int u, int v) {
        u = find(u); v= find(v);
        if(u == v) return;
        parent[u] = v;
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        String[] input;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                int tmp = Integer.parseInt(input[j]);
                adj[i][j] = tmp;
            }
        }
        List<Integer> route = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j] == 1) merge(i, j);
            }
        }

        String res = "YES";
        int pNum = find(route.get(0) - 1);
        for(int i = 1; i < m; i++) {
            if(find(route.get(i) - 1) != pNum) {
                res = "NO";
                break;
            }
        }
        bw.write(res);
        bw.flush();
        bw.close();
    }
}
