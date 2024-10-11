import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, k;
    static int[][] adj;
    static boolean[] visited;
    static int res = Integer.MAX_VALUE;

    static void floyd() {
        for(int m = 0; m < n; m++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][m] + adj[m][j]);
                }
            }
        }
    }

    static boolean allVisited() {
        for(int i = 0; i < n; i++)
            if(visited[i] == false) return false;
        return true;
    }    

    static void dfs(int here, int sum, int cnt) {
        if(allVisited()) {
            res = Math.min(res, sum);
            return;
        }

        for(int next = 0; next < n; next++) {
            if(visited[next]) continue;
            visited[next] = true;
            dfs(next, sum + adj[here][next], cnt + 1); 
            visited[next] = false; 
        }

    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);

        adj = new int[n][n];
        visited = new boolean[n];

        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                adj[i][j] = Integer.parseInt(input[j]);
            }
        }

        floyd();

        visited[k] = true;
        dfs(k, 0, 1);
        visited[k] = false;

        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
