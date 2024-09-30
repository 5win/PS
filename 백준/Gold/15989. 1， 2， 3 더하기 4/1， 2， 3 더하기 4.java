import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[][] dp = new int[4][10001];

    static int dfs(int prev, int sum) {

        if(sum == n) {
            return 1;
        } else if(sum > n) {
            return 0;
        }

        if(dp[prev][sum] != -1) {
            return dp[prev][sum];
        }

        int ret = 0;
        for(int next = prev; next <= 3; next++) {
            ret += dfs(next, sum + next);
        }
        return dp[prev][sum] = ret;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        while(T-- > 0) {
            for(int i = 1; i < 4; i++)
                Arrays.fill(dp[i], -1);

            n = sc.nextInt();
            System.out.println(dfs(1, 0));
        }
    }
}
