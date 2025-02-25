import java.util.*;

class Solution {
    
    int n, m;
    String[][] park;
    
    public boolean validate(int y, int x, int l) {
        for(int i = y; i <= y + l; i++) {
           	for(int j = x; j <= x + l; j++) {
                if(!park[i][j].equals("-1")) return false;
            } 
        }
        return true;
    }
    
    public int solution(int[] mats, String[][] park) {
        
		n = park.length;
        m = park[0].length;
        this.park = park;
        
        int mLen = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // cant
                if(!park[i][j].equals("-1")) continue;
                
                for(int l = 0; l <= 20; l++) {
                 	if(i + l < n && j + l < m && validate(i, j, l)) {
                    	mLen = Math.max(mLen, l + 1);    
                    }   
                }
            }
        }
        
        Arrays.sort(mats);
        for(int i = mats.length - 1; i >= 0; i--) {
            if(mats[i] <= mLen) return mats[i];
        }
		return -1; 
    }
}