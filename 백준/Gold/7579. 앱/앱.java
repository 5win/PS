import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        int[] m = new int[n];
        int[] c = new int[n];

        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) m[i] = Integer.parseInt(input[i]);
        
        input = br.readLine().split(" ");
        for(int i = 0; i < n; i++) c[i] = Integer.parseInt(input[i]);

        final int maxC = 10000;
        int[][] dp = new int[n][maxC + 1];

        for(int j = 0; j <= maxC; j++) {
            if(j >= c[0])
                dp[0][j] = m[0];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= maxC; j++) {
                if(j < c[i])
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            }
        }

        int res = Integer.MAX_VALUE;
        for(int j = 0; j <= maxC; j++) 
            if(dp[n - 1][j] >= M) res = Math.min(res, j);

        bw.write(String.valueOf(res));


        bw.flush();
        bw.close();
    }
}
