import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int n, m, r;
    static int[][] adj;
    static int[] t;

    static void floyd() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    static int calcMax() {
        int ret = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(adj[i][j] <= m) {
                    sum += t[j];
                }
            }
            ret = Math.max(ret, sum);
        }
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        r = Integer.parseInt(input[2]);

        adj = new int[n][n];
        t = new int[n];

        for(int i = 0; i < n; i++) {
            Arrays.fill(adj[i], INF);
            adj[i][i] = 0;
        }

        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            t[i] = Integer.parseInt(input[i]);
        }
        for(int i = 0; i < r; i++) {
            input = br.readLine().split(" ");
            int n1 = Integer.parseInt(input[0]);
            int n2 = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            n1--; n2--;
            adj[n1][n2] = cost;
            adj[n2][n1] = cost;
        }

        floyd();
        int res = calcMax();
        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
