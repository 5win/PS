import java.util.*;

class Solution {
    int n;
    
    public int lowerBound(int[] weights, int lo, int hi, int target, int dist) {
       	 
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if(weights[mid] * dist >= target) {
               	hi = mid; 
            } else {
                lo = mid;
            }
        }
        return hi;
    }
    
    public int upperBound(int[] weights, int lo, int hi, int target, int dist) {
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if(weights[mid] * dist <= target) {
               	lo = mid; 
            } else {
               	hi = mid; 
            }
        }
        return hi;
    }
    
    public long solution(int[] weights) {
        n = weights.length;
        
        // sort
        Arrays.sort(weights);
        
        // select left one
        long ans = 0;
        for(int i = 0; i < n; i++) {
            int w = weights[i];
            // 2, 3, 4m
            int startIdx = i;
			int l = lowerBound(weights, startIdx, n, w * 2, 2);
            int r = upperBound(weights, startIdx, n, w * 2, 2);
            ans += (r - l);
            for(int m1 = 2; m1 <= 4; m1++) {
                for(int m2 = 2; m2 < m1; m2++) {
                	int left = lowerBound(weights, startIdx, n, w * m1, m2);
                	int right = upperBound(weights, startIdx, n, w * m1, m2);
                   	ans += (right - left); 
                    //System.out.println(i + ", " + m1 + ", " + m2 + ", " + left + ", " + right);
                }
            }
        }
       	return ans; 
    }
}