import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n;
    static int[] dp;

    static int dfs(int here) {

        if(here == n + 1) {
            return 1;
        }

        if(dp[here] != -1) return dp[here];

        int ret = 0;
        if(here + 2 <= n + 1) {
            ret += 3 * dfs(here + 2);
        }
        for(int i = 4; i <= n; i += 2) {
            if(here + i > n + 1) continue;
            ret += 2 * dfs(here + i);
        }
        return dp[here] = ret;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        dp = new int[n + 1];
        Arrays.fill(dp, -1);

        int res = dfs(1);
        System.out.println(res);
    }
}
