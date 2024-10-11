import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int n, m, k;
    static int[][] adj;
    static int[] c;

    static void floyd() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    static List<Integer> calcRes() {
        List<Integer> ret = new ArrayList<>();
        int gMin = INF;
        for(int x = 0; x < n; x++) {
            int max = 0;
            for(int i = 0; i < k; i++) {
                int node = c[i] - 1;
                max = Math.max(max, adj[node][x] + adj[x][node]); 
            }
            if(max < INF) {
                if(max < gMin) {
                    gMin = max;
                    ret.clear();
                    ret.add(x + 1);
                } else if(max == gMin) {
                    ret.add(x + 1);
                }
            }
        }
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        c = new int[n];
        adj = new int[n][n];
        for(int i = 0; i < n; i++) {
            Arrays.fill(adj[i], INF);
            adj[i][i] = 0;
        }
        for(int i = 0; i < m; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;
            adj[src][dst] = Math.min(adj[src][dst], cost);
        }
        k = Integer.parseInt(br.readLine());
        input = br.readLine().split(" ");
        for(int i = 0; i < k; i++)
            c[i] = Integer.parseInt(input[i]);

        floyd();

        List<Integer> res = calcRes();
        Collections.sort(res);
        for(int i : res)
            bw.write(i + " ");

        bw.flush();
        bw.close();
    }
}
