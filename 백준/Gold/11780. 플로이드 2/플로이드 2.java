import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int n, m;
    static int[][] adj;
    static int[][] route;

    static void floyd() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    int cur = adj[i][k] + adj[k][j];
                    if(adj[i][j] > cur) {
                        adj[i][j] = cur;
                        route[i][j] = k;
                    }
                }
            }
        }
    }

    static void routing(int src, int dst, List<Integer> path) {
        int mid = route[src][dst];
        if(mid == -1) {
            path.add(src);
            if(src != dst)
                path.add(dst);
            return;
        }

        routing(src, mid, path);
        path.remove(path.size() - 1);
        routing(mid, dst, path);
    }

    static void print(List<Integer> path) {
        System.out.print(path.size() + " ");
        for(int i : path) {
            System.out.print(i + 1 + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        adj = new int[n][n];
        route = new int[n][n];

        for(int i = 0; i < n; i++) {
            Arrays.fill(adj[i], INF);
            Arrays.fill(route[i], -1);
            adj[i][i] = 0;
        }

        for(int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;
            adj[src][dst] = Math.min(adj[src][dst], cost);
        }

        floyd();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(adj[i][j] == INF)
                    System.out.print("0 ");
                else  
                    System.out.print(adj[i][j] + " ");
            }
            System.out.println();
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || adj[i][j] == INF) {
                    System.out.println(0);
                    continue;
                }
                List<Integer> path = new ArrayList<>();
                routing(i, j, path);
                print(path);
            }
        }
        
        bw.flush();
        bw.close();
    }
}
