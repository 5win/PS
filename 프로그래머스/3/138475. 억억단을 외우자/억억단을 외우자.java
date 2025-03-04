class Solution {
    
    public int[] solution(int e, int[] starts) {
        
        // counting
    	int[] cnt = new int[e + 1];
        for(int i = 1; i <= e; i++) {
            for(int j = 1; j <= e; j++) {
                int cur = i * j;
                if(cur > e) break;
                cnt[cur]++;
            }
        }
        
        // max cnt
        int max = cnt[e];
        int num = e;
        cnt[e] = num;
        for(int i = e - 1; i > 0; i--) {
            if(cnt[i] < max) {
                cnt[i] = num;
            } else {
                max = cnt[i];
               	num = i; 
                cnt[i] = num;
            }
        }
        
        int[] res = new int[starts.length];
        for(int i = 0; i < starts.length; i++) {
          	res[i] = cnt[starts[i]];  
        }
        return res;
    }
}