import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    static int n;
    static int[][] board;
    static long[][] dp;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = sc.nextInt();
        board = new int[n][n];
        dp = new long[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int dist = board[i][j];
                if(dist == 0) continue;
                if(i + dist < n) {
                    dp[i + dist][j] += dp[i][j];
                }
                if(j + dist < n) {
                    dp[i][j + dist] += dp[i][j];
                }
            }
        }
        System.out.println(dp[n - 1][n - 1]);
    }
}
