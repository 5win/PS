class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = -1;
        
        int[][] box = new int[100001][2];
        box[n - 1][0] = deliveries[n - 1];
        box[n - 1][1] = pickups[n - 1];
       	for(int i = n - 2; i >= 0; i--) {
           	box[i][0] = box[i + 1][0] + deliveries[i];
           	box[i][1] = box[i + 1][1] + pickups[i];
        } 
        
        long dist = 0;
        int cnt = 0;
        int s = n, e = n - 1;
       	
        while(0 < s && box[s - 1][0] == 0 && box[s - 1][1] == 0) s--;
        
        while(0 <= s && 0 <= e) {
            if(box[e][0] - cnt <= cap && box[e][1] - cnt <= cap) {
                e--;
            } else {
               	dist += 2 * s; 
                s = e + 1;
                cnt += cap;
            }
        }
        dist += 2 * s;
        
        return answer = dist;
    }
}