import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[201];
        for(int i = 0; i < n; i++) 
            arr[i] = Integer.parseInt(br.readLine());

        int[] dp = new int[201];
        Arrays.fill(dp, 1);
        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
        int maxLen = Arrays.stream(dp).max().getAsInt();
        bw.write(String.valueOf(n - maxLen));

        bw.flush();
        bw.close();
    }
}
