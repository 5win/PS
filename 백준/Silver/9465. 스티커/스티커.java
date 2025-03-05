import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n;
    static int[][] arr;
    static int[][] dp;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            n = sc.nextInt();
            arr = new int[2][n];
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < n; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }

            dp = new int[2][n];
            dp[0][0] = arr[0][0];
            dp[1][0] = arr[1][0];
            for(int j = 1; j < n; j++) {
                dp[0][j] = Math.max(dp[0][j - 1], dp[1][j - 1] + arr[0][j]);
                dp[1][j] = Math.max(dp[1][j - 1], dp[0][j - 1] + arr[1][j]);
            }
            System.out.println(Math.max(dp[0][n - 1], dp[1][n - 1]));
        }
    }
}
