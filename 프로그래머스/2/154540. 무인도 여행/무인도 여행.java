import java.util.*;

class Solution {
    int n, m;
    String[] maps;
    boolean[][] visited;
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    public boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    
    public int bfs(int sy, int sx) {
        Queue<int[]> q = new LinkedList<>();
        visited[sy][sx] = true;
        q.offer(new int[]{sy, sx});
        
       	int ret = 0; 
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int y = here[0], x = here[1];
            
            ret += maps[y].charAt(x) - '0';
            
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || maps[ny].charAt(nx) == 'X' || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                q.offer(new int[]{ny, nx});
            }
        }
        return ret;
    }
    
    public int[] solution(String[] maps) {
        this.n = maps.length;
        this.m = maps[0].length();
        this.maps = maps;
        this.visited = new boolean[n][m];
        
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
            	if(maps[i].charAt(j) == 'X' || visited[i][j]) continue;    
                
                int foods = bfs(i, j);
                if(foods > 0) {
                    res.add(foods);
                }
            }
        }
        if(res.size() == 0) {
            return new int[]{-1};
        }
        return res.stream().sorted().mapToInt(Integer::intValue).toArray();
    }
}