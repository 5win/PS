import java.util.*;

class Solution {
    
    int[] diffs, times;
    long limit;
    
    public boolean decision(int level) {
        long sum = diffs[0] <= level ? times[0] : (diffs[0] - level + 1) * times[0];
        for(int i = 1; i < diffs.length; i++) {
            sum += diffs[i] <= level ? times[i] : (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
        }
        return sum <= limit;
    }
    
    public int binarySearch(int level) {
       	int lo = 0, hi = level;
        
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if(decision(mid)) {
               	hi = mid; 
            } else{
           		lo = mid; 
            }
        }
        return hi;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {
       	 
        this.diffs = diffs;
        this.times = times;
        this.limit = limit;
        
        int level = diffs[0];
        for(int diff : diffs) {
            level = Math.max(level, diff);
        }
        
        return binarySearch(level);
    }
}