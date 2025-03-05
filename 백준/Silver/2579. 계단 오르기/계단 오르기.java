import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[] arr;
    static int[][] dp;
    static final int INF = 1987654321;

    public static int dfs(int here, int prev) {
        if(here >= n) return -INF;
        if(here == n - 1) {
            return arr[here];
        }

        if(dp[here][prev] != -1) {
            return dp[here][prev];
        }
        
        int ret = 0;
        if(prev == 1) {
            ret = dfs(here + 2, 0);
        } else {
            ret = dfs(here + 1, 1);
            ret = Math.max(ret, dfs(here + 2, 0));
        }
        return dp[here][prev] = ret + arr[here];
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];
        dp = new int[n][2];

        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            Arrays.fill(dp[i], -1);
        }

        int res = dfs(0, 0);
        res = Math.max(res, dfs(1, 0));

        System.out.println(res);
    }
}
