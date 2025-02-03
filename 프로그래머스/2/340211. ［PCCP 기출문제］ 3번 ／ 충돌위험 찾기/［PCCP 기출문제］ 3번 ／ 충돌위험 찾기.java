import java.util.*;

class Solution {
   	
    int n, m, x;
    List<int[]>[] path;
    int[][] points, routes;
    
    public void makePath(int num) {
       	int[] route = routes[num]; 
        
        path[num].add(points[route[0] - 1]);
        for(int i = 0; i < m - 1; i++) {
           	int[] here = points[route[i] - 1];
            int[] next = points[route[i + 1] - 1];
           	
            int y = here[0], x = here[1];
            while(y != next[0]) {
               	y = y < next[0] ? y + 1 : y - 1;
                path[num].add(new int[]{y, x});
            }
            
            while(x != next[1]) {
                x = x < next[1] ? x + 1 : x - 1;
                path[num].add(new int[]{y, x});
            }
        }
    }
    
    public int calcCnt() {
       	int res = 0; 
        int t = 0;
        int[][] cnt = new int[101][101];
        
        while(true) {
            // init to 0
            for(int i = 0; i < 101; i++) {
                Arrays.fill(cnt[i], 0);
            }
            
            // visit
            boolean isFinished = true;
           	for(int robot = 0; robot < x; robot++) {
                if(path[robot].size() <= t) continue;
                
                int[] here = path[robot].get(t);
               	cnt[here[0]][here[1]]++; 
                isFinished = false;
            } 
            
            // break?
            if(isFinished) break;
            
            // counting
            for(int i = 1; i < 101; i++) {
                for(int j = 1; j < 101; j++) {
                    if(cnt[i][j] >= 2) res++;
                }
            }
            
            // time + 1
            t++;
        }
        return res;
    }
    
    public int solution(int[][] points, int[][] routes) {
        this.points = points;
        this.routes = routes;
        n = points.length;
        x = routes.length;
        m = routes[0].length;
        
        path = new ArrayList[x];
        for(int i = 0; i < x; i++) {
            path[i] = new ArrayList<>();
        }
        
        // logic
        for(int robot = 0; robot < x; robot++) {
            makePath(robot);
        }
       	
        return calcCnt();
    }
}