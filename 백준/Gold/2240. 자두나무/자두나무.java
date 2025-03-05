import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;
    static int n, k;
    static int t, w;
    static int[] arr;
    static int[][][] dp;

    static int dfs(int here, int loc, int moved) {

        if(here == t) {
            return 0;
        }

        if(dp[here][loc][moved] != -1) return dp[here][loc][moved];

        int ret = 0;
        if(arr[here] == loc) {
            ret = dfs(here + 1, loc, moved) + 1;
        } else {
            if(moved + 1 <= w) {
                ret = dfs(here + 1, loc % 2 + 1, moved + 1) + 1;
            }
            ret = Math.max(ret, dfs(here + 1, loc, moved));
        }
        return dp[here][loc][moved] = ret;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        w = sc.nextInt();

        arr = new int[t];
        dp = new int[t][3][w + 1];
        for(int i = 0; i < t; i++) {
            arr[i] = sc.nextInt();
        }

        for(int i = 0; i < t; i++) {
            for(int j = 0; j < 3; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        int res = dfs(0, 1, 0);
        System.out.println(res);

    }
}
