class Solution {
    
    int[][] maze;
    int[] rSrc, rDst, bSrc, bDst;
    int n, m;
    int[][] rDist, bDist;
    
   	int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    
    int res = 1987654321;
    
    public boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }
    
    public void bDfs(int y, int x) {
        
        if(maze[y][x] == 4) {
           	res = Math.min(res, Math.max(rDist[rDst[0]][rDst[1]], bDist[y][x]));
                
                /**
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        System.out.print(rDist[i][j]);
                    }
                    System.out.println();
                }
                    System.out.println();
                    **/
            return;
        }
        
      	for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || bDist[ny][nx] != 0 || maze[ny][nx] == 5) continue;
            // 이미 빨간색이 도착한 곳을 지나는 경우
            if(maze[ny][nx] == 3 && rDist[ny][nx] <= bDist[y][x] + 1) continue;
            if(maze[ny][nx] == 4 && rDist[ny][nx] >= bDist[y][x] + 1) continue;
            if(rDist[ny][nx] == bDist[y][x] + 1) continue;
            // intersect
            if(bDist[y][x] + 1 == rDist[y][x] && bDist[y][x] == rDist[ny][nx]) continue;
            
            bDist[ny][nx] = bDist[y][x] + 1;
            bDfs(ny, nx);
            bDist[ny][nx] = 0;
        }
    }
    
    public void rDfs(int y, int x) {
        
        if(maze[y][x] == 3) {
            // blue
            bDfs(bSrc[0], bSrc[1]);
            return;
        }
        
      	for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || rDist[ny][nx] != 0 || maze[ny][nx] == 5) continue;
            
            rDist[ny][nx] = rDist[y][x] + 1;
            rDfs(ny, nx);
            rDist[ny][nx] = 0;
        }
    }
    
    
    public int solution(int[][] maze) {
   		
        this.maze = maze;
        n = maze.length;
        m = maze[0].length;
        
        rDist = new int[n][m];
        bDist = new int[n][m];
        
       	for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == 1) {
                    rSrc = new int[]{i, j};
                } else if(maze[i][j] == 2) {
                    bSrc = new int[]{i, j};
                } else if(maze[i][j] == 3) {
                    rDst = new int[]{i, j};
                } else if(maze[i][j] == 4) {
                    bDst = new int[]{i, j};
                }
            }
        } 
        
        rDist[rSrc[0]][rSrc[1]] = 1;
        bDist[bSrc[0]][bSrc[1]] = 1;
        
        rDfs(rSrc[0], rSrc[1]);
        
        return res == 1987654321 ? 0 : res - 1;
    }
}