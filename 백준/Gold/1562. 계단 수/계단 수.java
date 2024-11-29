import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int MOD = (int) 1e9;

    static int n;
    static int dp[][][];

    static boolean check(String s) {
        int[] cnt = new int[10];
        for(char c : s.toCharArray()) {
            cnt[c - '0']++;
        }
        for(int i = 0; i < 10; i++) {
            if(cnt[i] == 0) return false;
        }
        return true;
    }

    static int dfs(int curNum, int remain, String s, int bit) {

        if(curNum < 0 || 9 < curNum) return 0;
        if(remain == 1) {
            s = s + curNum;
            if(check(s)) {
                // System.out.println(curNum + ", " + s);
                return 1;
            }
            return 0;
        }

        if(dp[curNum][remain][bit] != -1) {
            return dp[curNum][remain][bit];
        }

        int sum = 0;
        sum = (sum + dfs(curNum - 1, remain - 1, s + curNum, bit | (1 << curNum))) % MOD;
        sum = (sum + dfs(curNum + 1, remain - 1, s + curNum, bit | (1 << curNum))) % MOD;

        return dp[curNum][remain][bit] = sum;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        dp = new int[10][101][1 << 10];
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 101; j++)
                Arrays.fill(dp[i][j], -1);

        if(n == 1) {
            bw.write("0\n");
            bw.flush();
            return;
        }
        int sum = 0;
        for(int i = 1; i < 10; i++) {
            int bit = 1 << i;
            sum = (sum + dfs(i - 1, n - 1, i + "", bit)) % MOD;
            sum = (sum + dfs(i + 1, n - 1, i + "", bit)) % MOD;
        }
        bw.write(sum + "\n");

        bw.flush();
        bw.close();
    }
}
