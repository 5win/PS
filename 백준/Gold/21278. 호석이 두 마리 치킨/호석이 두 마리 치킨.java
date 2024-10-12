import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int INF = (int)1e9;
    static int n, m;
    static int[][] adj;
    static int A, B, res;

    static void floyd() {
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
    }

    static void calc() {
        int min = INF;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int sum = 0;
                for(int l = 0; l < n; l++) {
                    sum += Math.min(adj[l][i], adj[l][j]);
                } 
                if(min > sum) {
                    min = sum;
                    A = i + 1;
                    B = j + 1;
                    res = sum * 2;
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
            src--; dst--;
            adj[src][dst] = 1;
            adj[dst][src] = 1;
        }

        floyd();
        calc();
        bw.write(A + " " + B + " " + res);

        bw.flush();
        bw.close();
    }
}
