import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = (int)1e9;
    static int v, e;
    static int[][] adj;


    static void floyd() {
        for(int k = 0; k < v; k++) {
            for(int i = 0; i < v; i++) {
                for(int j = 0; j < v; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    static int calcMin() {
        int ret = INF;
        for(int i = 0; i < v; i++) {
            for(int j = i + 1; j < v; j++) {
                ret = Math.min(ret, adj[i][j] + adj[j][i]);
            }
        }
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        v = Integer.parseInt(input[0]);
        e = Integer.parseInt(input[1]);

        adj = new int[v][v];
        for(int i = 0; i < v; i++) {
            Arrays.fill(adj[i], INF);
            adj[i][i] = 0;
        }

        for(int i = 0; i < e; i++) {
            input = br.readLine().split(" ");
            int src = Integer.parseInt(input[0]);
            int dst = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);
            src--; dst--;
            adj[src][dst] = cost;
        }
        floyd();
        int res = calcMin();
        if(res == INF)
            bw.write("-1\n");
        else
            bw.write(res + "\n");        

        bw.flush();
        bw.close();
    }
}
