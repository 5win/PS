import java.util.*;

class Solution {
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    int N;
    
    boolean inRange(int y, int x) {
        return 0 <= y && y < N && 0 <= x && x < N;
    }
    
    public int[][] solution(int n) {
        N = n;
        int[][] answer = new int[n][n];
        for(int i = 0; i < n; i++) {
        	Arrays.fill(answer[i], 0);
        }
       
       	int y = 0, x = 0;
        int dir = 0;
        for(int i = 1; i <= n * n; i++) {
            answer[y][x] = i;
            
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || answer[ny][nx] != 0) {
               	dir = (dir + 1) % 4; 
            }
            y += dy[dir];
            x += dx[dir];
        }
        
        return answer;
    }
}