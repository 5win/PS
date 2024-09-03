import java.util.*;

class Solution {
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    boolean inRange(int y, int x, int n) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }
    
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
       
       	int y = 0, x = 0;
        int dir = 0;
        for(int i = 1; i <= n * n; i++) {
            answer[y][x] = i;
            
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx, n) || answer[ny][nx] != 0) {
               	dir = (dir + 1) % 4; 
            }
            y += dy[dir];
            x += dx[dir];
        }
        
        return answer;
    }
}