import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        
        Arrays.sort(targets, (a, b) -> {
           	if(a[1] == b[1]) {
                return a[0] - b[0];
            } 
            return a[1] - b[1];
        });
        
        int res = 0;
        int lastEnd = targets[0][1];
        for(int i = 1; i < targets.length; i++) {
       		int[] here = targets[i];
           	if(here[0] >= lastEnd) {
                System.out.println(here[0]);
               	res++;
                lastEnd = here[1];
            } 
        }
        res++;
        
        return res;
    }
}