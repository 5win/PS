import java.util.*;

class Solution {
    String[] maps;
    int n, m;
    
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    public boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    
    public int bfs(int[] src, int[] dst) {
        Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[n][m];
        
        q.offer(src);
        dist[src[0]][src[1]] = 1;
       	
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int y = here[0], x = here[1];
            
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || dist[ny][nx] != 0 || maps[ny].charAt(nx) == 'X') continue;
                q.offer(new int[]{ny, nx});
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
       	return dist[dst[0]][dst[1]] - 1; 
    }
    
    public int solution(String[] maps) {
        this.maps = maps;
		n = maps.length;
        m = maps[0].length();
        
        int[] start = null, end = null, lever = null;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maps[i].charAt(j) == 'S') {
                   	start = new int[]{i, j}; 
                } else if(maps[i].charAt(j) == 'E') {
                    end = new int[]{i, j};
                } else if(maps[i].charAt(j) == 'L') {
                    lever = new int[]{i, j};
                }
            }
        }
        
        int d1 = bfs(start, lever);
        int d2 = bfs(lever, end);
        
        if(d1 == -1 || d2 == -1) return -1;
        return d1 + d2;
    }
}