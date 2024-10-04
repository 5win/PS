class Solution {
    public int solution(int n, int[] tops) {
        int answer = 0;
        final int MOD = 10007;
        
       	int[][] dp = new int[100001][4]; 
        
        dp[0][0] = 1;
        dp[0][1] = tops[0] == 1 ? 1 : 0;
        dp[0][2] = 1;
        dp[0][3] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3]) % MOD;
            if(tops[i] == 1)
            	dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i  -1][3]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i  -1][3]) % MOD;
        }
        
        for(int i = 0; i < 4; i++)
            answer = (answer + dp[n - 1][i]) % MOD;
        return answer;
    }
}