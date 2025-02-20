import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        
        int wonhoA = scores[0][0];
        int wonhoB = scores[0][1];
        
        Arrays.sort(scores, (a, b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return b[0] - a[0];
        });
        
        int rank = 1;
        int maxB = 0;
        for(int i = 0; i < scores.length; i++) {
            int[] cur = scores[i];
            // 원호 인센티브X
            if(cur[0] > wonhoA && cur[1] > wonhoB) {
                return -1;
            }
            // 인센티브X
            if(cur[1] < maxB) continue;
            maxB = Math.max(maxB, cur[1]);
            
            // calc rank
           	if(cur[0] + cur[1] > wonhoA + wonhoB) {
                rank++;
            } 
        }
       	return rank; 
    }
}