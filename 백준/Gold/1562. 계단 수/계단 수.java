import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static final int MOD = (int) 1e9;

    static int n;
    static int dp[][][];

    static int dfs(int prev, int remain, int bit) {

        if(remain == 0) {
            if(bit == (1 << 10) - 1) {
                return 1;
            }
            return 0;
        }

        if(dp[prev][remain][bit] != -1) {
            return dp[prev][remain][bit];
        }
        int sum = 0;
        if(0 < prev)
            sum = (sum + dfs(prev - 1, remain - 1, bit | (1 << (prev - 1)))) % MOD;
        if(prev < 9)
            sum = (sum + dfs(prev + 1, remain - 1, bit | (1 << (prev + 1)))) % MOD;

        return dp[prev][remain][bit] = sum;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        dp = new int[10][101][1 << 10];
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 101; j++)
                Arrays.fill(dp[i][j], -1);

        int sum = 0;
        for(int i = 1; i < 10; i++) {
            sum = (sum + dfs(i, n - 1, 1 << i)) % MOD;
        }
        bw.write(sum + "\n");

        bw.flush();
        bw.close();
    }
}
