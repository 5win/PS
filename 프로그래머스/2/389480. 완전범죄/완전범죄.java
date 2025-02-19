import java.util.*;

class Solution {
    
    int[][] info;
    int n, m;
    int[][][] dp;
    
    public int dfs(int here, int a, int b) {
        
        if(here == info.length) {
            return a;
        }
        
        if(dp[here][a][b] != -1) {
            return dp[here][a][b];
        }
        
        int ret = Integer.MAX_VALUE;
        if(a + info[here][0] < n) {
       		ret = Math.min(ret, dfs(here + 1, a + info[here][0], b));
        }
        if(b + info[here][1] < m) {
       		ret = Math.min(ret, dfs(here + 1, a, b + info[here][1]));
        }
        
        return dp[here][a][b] = ret;
    }
    
    public int solution(int[][] info, int n, int m) {
        this.info = info;
        this.n = n;
        this.m = m;
        
        dp = new int[info.length][n][m];
        for(int i = 0; i < info.length; i++) {
            for(int j = 0; j < n; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        
        int ans = dfs(0, 0, 0);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}