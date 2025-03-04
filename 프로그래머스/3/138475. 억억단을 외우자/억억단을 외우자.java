class Solution {
    
    int[] cnt = new int[5000001];
    public int[] solution(int e, int[] starts) {
        
        // counting
        for(int i = 1; i <= 5000000; i++) {
            for(int j = 1; j <= 5000000; j++) {
                int cur = i * j;
                if(cur > 5000000) break;
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