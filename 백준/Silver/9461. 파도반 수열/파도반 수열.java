import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n, k;
    static int[] arr;
    static long[] dp;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        dp = new long[101];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 2;
        for(int i = 5; i <= 100; i++) {
            dp[i] = dp[i - 1] + dp[i - 5];
        }

        int t = sc.nextInt();
        while(t-- > 0) {
            n = sc.nextInt();
            System.out.println(dp[n - 1]);
        }
    }
}
