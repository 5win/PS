import java.util.*;

class Solution {
    
    int n, m;
    int[][] q;
    int[] ans;
    
    public boolean calc(List<Integer> list) {
        
       	int res = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j : q[i]) {
               	if(list.indexOf(j) >= 0) {
                   	cnt++; 
                }
            }
           	if(ans[i] != cnt) {
                return false;
            } 
        }
        return true;
    }
    
    public int dfs(int num, List<Integer> res, boolean[] visited) {
        if(res.size() == 5) {
           	if(calc(res)) return 1;
            return 0;
        }
        if(num > n) return 0;
       	
        // dfs
        int ret = 0;
     	ret += dfs(num + 1, res, visited);
        
        if(!visited[num]) {
            visited[num] = true;
            res.add(num);
           	ret += dfs(num + 1, res, visited); 
            res.remove(res.size() - 1);
            visited[num] = false;
        }
        return ret;
    }
    
    public int solution(int n, int[][] q, int[] ans) {
        this.n = n;
        this.m = ans.length;
        this.q = q;
        this.ans = ans;
        
		int ret = dfs(1, new ArrayList<>(), new boolean[n + 1]);        
        return ret;
    }
}