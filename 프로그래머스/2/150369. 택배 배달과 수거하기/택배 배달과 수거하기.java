class Solution {
    
    int[] deliSum, pickSum;
    
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        
        deliSum = new int[n + 1];
        pickSum = new int[n + 1];
        
        // prefix sum
        final int INF = 987654321;
        deliSum[0] = INF;
        pickSum[0] = INF;
        deliSum[n] = deliveries[n - 1];
        pickSum[n] = pickups[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            deliSum[i + 1] = deliSum[i + 2] + deliveries[i];
            pickSum[i + 1] = pickSum[i + 2] + pickups[i];
        }
        
        // move
        int loc = n;
        for(int i = n; i > 0; i--) {
            if(deliSum[i] > 0 || pickSum[i] > 0) {
                loc = i;
                break;
            }
        }
        
        int deliCnt = 0, pickCnt = 0;
        long moved = 0;
        for(int i = n; i > 0;) {
        	int curDeli = deliSum[i] - deliCnt;
            int curPick = pickSum[i] - pickCnt;
            if(curDeli > cap || curPick > cap) {
                //deliCnt += Math.min(curDeli, cap);
                //pickCnt += Math.min(curPick, cap);
                deliCnt += cap;
                pickCnt += cap;
                moved += loc * 2;
                loc = i;
                //System.out.println(moved);
            } else {
               	i--; 
            }
        }
        if(deliCnt != deliSum[1] || pickCnt != pickSum[1]) {
         	moved += loc * 2;
       	//deliCnt += deliSum[1] - deliCnt;
        //pickCnt += pickSum[1] - pickCnt;
        }
            
       	return moved; 
    }
}