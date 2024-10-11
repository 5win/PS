import java.util.*;

class Solution {
    int n, m, x, y, r, c, k;
    int[] dx = {1, 0, 0, -1};
    int[] dy = {0, -1, 1, 0};
    char[] dirChar = {'d', 'l', 'r', 'u'};
    String res = null;
    boolean isFinish = false;
    
    int calcDist(int a, int b) {
       	return Math.abs(r - a) + Math.abs(c - b); 
    }
    
    boolean inRange(int a, int b) {
        return 0 <= a && a < n && 0 <= b && b < m;
    }
    
    void dfs(int cx, int cy, int remain, StringBuilder sb) {
        if(isFinish) return;
        
        if(remain == 0) {
        	if(cx == r && cy == c) {
                res = sb.toString();
                isFinish = true;
            }
            return;
        }
        
        int requireMove = calcDist(cx, cy);
		if(requireMove > remain) return;
        if((remain - requireMove) % 2 == 1) return;
        
       	for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(!inRange(nx, ny)) continue;
            sb.append(dirChar[dir]);
            dfs(nx, ny, remain - 1, sb);
            sb.deleteCharAt(sb.length() - 1); 
        } 
    }
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        String answer = "";
        x--; y--; r--; c--;
   		this.n = n; this.m = m; this.x = x; this.y = y;
        this.r = r; this.c = c; this.k = k;
        
        StringBuilder sb = new StringBuilder("");
       	dfs(x, y, k, sb); 
        
        if(res == null) 
            answer = "impossible";
        else
            answer = res;
        
        return answer;
    }
}