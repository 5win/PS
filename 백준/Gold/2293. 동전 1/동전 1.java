import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n, k;
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        arr = new int[n + 1];
        for(int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }

        dp = new int[n + 1][k + 1];
        for(int i = 1; i <= n; i++) {
            int cost = arr[i];
            dp[i][0] = 1;
            for(int j = 1; j <= k; j++) {
                if(j - cost >= 0) {
                    dp[i][j] = dp[i][j - cost] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[n][k]);
    }
}
