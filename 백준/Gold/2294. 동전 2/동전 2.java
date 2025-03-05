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

    static int dfs(int here, int sum) {

        if(sum == k) {
            return 0;
        }

        if(dp[here][sum] != -1) {
            return dp[here][sum];
        }

        int ret = INF;
        for(int next = here; next < n; next++) {
            if(sum + arr[next] > k) continue;
            ret = Math.min(ret, dfs(next, sum + arr[next]));
        }
        return dp[here][sum] = ret + 1;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        k = sc.nextInt();
        arr = new int[n];
        dp = new int[n][k + 1];

        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            Arrays.fill(dp[i], -1);
        }

        int res = dfs(0, 0);
        res = res >= INF ? -1 : res;
        System.out.println(res);
    }
}
