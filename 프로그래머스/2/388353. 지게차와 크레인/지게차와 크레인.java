import java.util.*;

class Solution {
    
    String[] storage;
    int n, m;
    boolean[][] deleted;
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    public boolean inRange(int y, int x) {
		return 0 < y && y <= n && 0 < x && x <= m;
    }
    public void deleteByGigae(char target) {
        
       	Queue<int[]> q = new LinkedList<>(); 
        boolean[][] visited = new boolean[n + 2][m + 2];
        q.offer(new int[]{0, 0});
        visited[0][0] = true;
        
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int y = here[0], x = here[1];
            
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
               	if(!(0 <= ny && ny <= n + 1 && 0 <= nx && nx <= m + 1)) continue;
                if(visited[ny][nx]) continue;
                
                visited[ny][nx] = true;
                
                if(deleted[ny][nx]) {
                	q.offer(new int[]{ny, nx});
                } else {
	                if(inRange(ny, nx) && storage[ny - 1].charAt(nx - 1) == target) {
                        deleted[ny][nx] = true;
                    }
                }
                /*
                if(deleted[y][x]) {
                   	q.offer(new int[]{ny, nx}); 
                }
                if(inRange(ny, nx) && storage[ny - 1].charAt(nx - 1) == target) {
            		deleted[ny][nx] = true; 
                } 
                */
            } 
        }
    }
    
    public void deleteByCrane(char target) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(storage[i - 1].charAt(j - 1) == target) {
                 	deleted[i][j] = true;
                }
            }
        }
    }
    
    public int solution(String[] storage, String[] requests) {
        
        this.storage = storage;
        this.n = storage.length;
        this.m = storage[0].length();
        deleted = new boolean[n + 2][m + 2];
        
        // init deleted
        Arrays.fill(deleted[0], true);
        Arrays.fill(deleted[n + 1], true);
       	for(int i = 1; i <= n; i++) {
            Arrays.fill(deleted[i], true);
            for(int j = 1; j <= m; j++) {
              	deleted[i][j] = false; 
            }
        } 
        
        for(String req : requests) {
            if(req.length() == 1) {
                deleteByGigae(req.charAt(0));
            } else {
                deleteByCrane(req.charAt(0));
            }
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
               	if(deleted[i][j] == false) cnt++; 
            }
        }
        
        return cnt;
    }
}