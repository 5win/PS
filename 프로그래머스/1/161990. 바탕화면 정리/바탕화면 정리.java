import java.util.*;

class Solution {
    
    List<int[]> files = new ArrayList<>();
    int n, m;
    final int INF = 1987654321;
    
    public int[] solution(String[] wallpaper) {
        n = wallpaper.length;
        m = wallpaper[0].length();
   		
        int minx = INF, maxx = 0;
        int miny = INF, maxy = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(wallpaper[i].charAt(j) == '#') {
                    miny = Math.min(miny, i);
                    maxy = Math.max(maxy, i);
                    
                    minx = Math.min(minx, j);
                    maxx = Math.max(maxx, j);
                }
            }
        }
       	
        return new int[]{miny, minx, maxy + 1, maxx + 1};
    }
}