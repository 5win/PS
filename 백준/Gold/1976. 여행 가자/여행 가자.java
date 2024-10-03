import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static int[][] adj = new int[201][201];

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

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        String[] input;
        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                int tmp = Integer.parseInt(input[j]);
                if(i == j) {
                    adj[i][j] = 0;
                    continue;
                }
                adj[i][j] = tmp == 0 ? Integer.MAX_VALUE / 2 - 1 : 1;
            }
        }
        List<Integer> route = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

        floyd();
        String res = "YES";
        for(int i = 0; i < m - 1; i++) {
            if(adj[route.get(i) - 1][route.get(i + 1) - 1] == Integer.MAX_VALUE / 2 - 1)
                res = "NO";
        }
        bw.write(res);
        bw.flush();
        bw.close();
    }
}
