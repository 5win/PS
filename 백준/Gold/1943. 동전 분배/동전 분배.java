import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n;
    static int[] cost = new int[101];
    static int[] cnt = new int[101];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input;
        boolean[] dp = new boolean[50001];
        int T = 3;
        while(T-- > 0) {
            n = Integer.parseInt(br.readLine());

            int sum = 0;
            for(int i = 1; i <= n; i++) {
                input = br.readLine().split(" ");
                cost[i] = Integer.parseInt(input[0]);
                cnt[i] = Integer.parseInt(input[1]);
                sum += cost[i] * cnt[i];
            }
    
            // for(int i = 0; i <= n; i++)
            //     dp[i][0] = true;
            Arrays.fill(dp, false);
            dp[0] = true;
                
            for(int i = 1; i <= n; i++) {
                int c = cost[i];
                for(int j = sum / 2; j >= c; j--) {
                    if(!dp[j - c]) continue;
                    for(int k = 0; k < cnt[i]; k++) {
                        if(j + c * k <= sum / 2)
                            dp[j + c * k] = true;
                    }
                }
            }

            // for(int i = 1; i <=n; i++) {
            //     for(int j = 1; j <= 300; j++)
            //         System.out.print(dp[i][j] ? 1 : 0);
            //     System.out.println();
            // }
    
            if(sum % 2 == 1) bw.write("0\n");
            else if(dp[sum / 2]) bw.write("1\n");
            else bw.write("0\n");
        }



        bw.flush();
        bw.close();
    }
}
