import java.util.*;

class Solution {
    
    int n, m;
    int[][] land;
    int[] res;
    boolean[][] visited;
    
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    public boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    
    public void bfs(int r, int c) {
        
        Queue<int[]> q = new LinkedList<>();
        Set<Integer> set = new HashSet<>();
       	
        set.add(c);
        q.offer(new int[]{r, c});
       	visited[r][c] = true; 
        
        int cnt = 1;
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int y = here[0], x = here[1];
            
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
               	if(!inRange(ny, nx) || land[ny][nx] == 0 || visited[ny][nx]) continue;
                set.add(nx);
                visited[ny][nx] = true;
               	cnt++;
                q.offer(new int[]{ny, nx});
            }
        } 
        
        for(int col : set) {
         	res[col] += cnt;
        }
    }
    
    public void calcSum() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && land[i][j] == 1)
                	bfs(i, j);
            }
        }
    }
    
    public int solution(int[][] land) {
       	this.land = land; 
       	n = land.length;
        m = land[0].length;
        visited = new boolean[n][m];
        res = new int[m];
        
        calcSum();
        int answer = 0;
        for(int i = 0; i < m; i++) {
            answer = Math.max(answer, res[i]);
        }
        return answer;
    }
}