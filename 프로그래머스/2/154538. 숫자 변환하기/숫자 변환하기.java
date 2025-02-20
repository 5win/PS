import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        final int INF = Integer.MAX_VALUE - 1;
        int[] dp = new int[1000001];
        Arrays.fill(dp, INF);
        
        dp[x] = 0;
        for(int i = x + 1; i <= y; i++) {
           	if(i - n >= 0) {
                dp[i] = Math.min(dp[i], dp[i - n] + 1);
            }
            if(i % 2 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 2] + 1);
            }
            if(i % 3 == 0) {
                dp[i] = Math.min(dp[i], dp[i / 3] + 1);
            }
        }
        
        return dp[y] == INF ? -1 : dp[y];
    }
}