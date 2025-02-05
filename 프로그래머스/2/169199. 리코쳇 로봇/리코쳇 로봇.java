import java.util.*;

class Solution {
    
    String[] board;
    int n, m;
    int[] start, end;
    
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    public boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    
    public int[] go(int y, int x, int dir) {
        
        int ny = y + dy[dir], nx = x + dx[dir];
        while(inRange(ny, nx) && board[ny].charAt(nx) != 'D') {
           	ny += dy[dir];
            nx += dx[dir];
        }
        //return new int[]{ny, nx};
        return new int[]{ny - dy[dir], nx - dx[dir]};
    }
    
    public int bfs() {
       	Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[n][m];
        
        q.offer(start);
        dist[start[0]][start[1]] = 1;
        
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int y = here[0], x = here[1];
            
            for(int dir = 0; dir < 4; dir++) {
				int[] next = go(y, x, dir);
                if(dist[next[0]][next[1]] != 0) continue;
                
                dist[next[0]][next[1]] = dist[y][x] + 1;
                q.offer(next);
            }
        }
        return dist[end[0]][end[1]] - 1;
    }
    
    public int solution(String[] board) {
       	this.board = board;
        n = board.length;
        m = board[0].length();
        
       	for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i].charAt(j) == 'R') {
                	start = new int[]{i, j};    
                } else if(board[i].charAt(j) == 'G') {
                	end = new int[]{i, j};    
                }
            }
        } 
        
        int res = bfs();
       	return res == 0 ? -1 : res; 
    }
}