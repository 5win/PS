import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int n, m;
    static int[][] adj;

    static void floyd() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
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

            if(cost == 0) {
                adj[src][dst] = 0;
                adj[dst][src] = 1;
            } else {
                adj[src][dst] = 0;
                adj[dst][src] = 0;
            }
        }

        floyd();

        int k = Integer.parseInt(br.readLine());
        while(k-- > 0) {
            input = br.readLine().split(" ");
            int s = Integer.parseInt(input[0]);
            int e = Integer.parseInt(input[1]);
            s--; e--;
            bw.write(adj[s][e] + "\n");
        }


        bw.flush();
        bw.close();
    }
}
