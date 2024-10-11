import java.util.*;

class Solution {
    
    int[][] p;
    int[][] dp = new int[301][301];
    int maxAl, maxCo;
    static final int INF = (int)1e9;
   	
    int dfs(int al, int co, int cnt) {
        
        if(cnt > 300) return INF;
      	
        if(al >= maxAl && co >= maxCo) {
            return 0;
        }
        
        if(dp[al][co] != -1) return dp[al][co];
        
        int ret = INF;
        if(al < maxAl)
        	ret = Math.min(ret, dfs(al + 1, co, cnt + 1) + 1);
        if(co < maxCo)
        	ret = Math.min(ret, dfs(al, co + 1, cnt + 1) + 1);
        for(int i = 0; i < p.length; i++) {
            if(p[i][0] <= al && p[i][1] <= co) {
                if(al >= maxAl) {
                	ret = Math.min(ret, dfs(al, co + p[i][3], cnt + 1) + p[i][4]);
                } else if(co >= maxCo) {
                	ret = Math.min(ret, dfs(al + p[i][2], co, cnt + 1) + p[i][4]);
                } else {
                	ret = Math.min(ret, dfs(al + p[i][2], co + p[i][3], cnt + 1) + p[i][4]);
                }
            }
        }
        return dp[al][co] = ret;
    }
    
    public int solution(int alp, int cop, int[][] problems) {
        int answer = 0;
        p = problems;
        
        for(int i = 0; i < p.length; i++) {
            maxAl = Math.max(maxAl, p[i][0]);
            maxCo = Math.max(maxCo, p[i][1]);
        }
        
        for(int i = 0; i < 301; i++)
        	Arrays.fill(dp[i], -1);
        
        answer = dfs(alp, cop, 0);
        
        return answer;
    }
}