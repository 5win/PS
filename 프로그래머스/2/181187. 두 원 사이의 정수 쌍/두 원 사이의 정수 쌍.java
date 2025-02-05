class Solution {
    public long solution(int r1, int r2) {
        
        if(r1 < r2) {
            int tmp = r2;
            r2 = r1;
            r1 = tmp;
        }
        
        // r1
        long sum1 = 0;
        for(int x = 1; x <= r1; x++) {
           	//double y = Math.sqrt(r1 * r1 - x * x); 
            long yy = (long)r1 * r1 - (long)x * x;
           	sum1 += (long) Math.sqrt(yy) + 1; 
        }
        sum1 *= 4;
        
        // r2
        long sum2 = 0;
        for(int x = 1; x <= r2; x++) {
           	//double y = Math.sqrt(r2 * r2 - x * x); 
            long yy = (long)r2 * r2 - (long)x * x;
            double y = Math.sqrt(yy);
            if(y == (long) y) {
                sum2 += (long) y;
            } else {
           		sum2 += (long) y + 1; 
            }
        }
       	sum2 *= 4; 
        
        return sum1 - sum2;
    }
}