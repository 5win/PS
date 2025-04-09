import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int INF = 1987654321;

    static String n;
    static Set<String> set = new HashSet<>();
    static int[] dp;

    static int dfs(int here) {

        if(here == n.length()) {
            return 1;
        }

        if(dp[here] != -1) {
            return dp[here];
        }

        int sum = 0;
        // 1자리 수
        String cur = n.substring(here, here + 1);
        if(set.contains(cur)) {
            sum += dfs(here + 1);
        }

        // 2자리 수
        if(here + 2 <= n.length()) {
            cur = n.substring(here, here + 2);
            if(set.contains(cur)) {
                sum += dfs(here + 2);
            }
        }

        return dp[here] = sum % 1_000_000;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        n = sc.nextLine();
        dp = new int[n.length() + 1];
        Arrays.fill(dp, -1);

        // mapping table
        for(int i = 1; i <= 26; i++) {
            set.add(Integer.toString(i));
        }

        System.out.println(dfs(0));

    }
}
