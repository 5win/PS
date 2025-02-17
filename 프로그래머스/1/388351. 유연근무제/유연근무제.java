class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
       	int n = schedules.length; 
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int tmp = schedules[i] % 100 + 10;
            int limit = tmp >= 60 ? (schedules[i] / 100 + 1) * 100 + tmp % 60 : (schedules[i] / 100) * 100 + tmp;
            
            int cnt = 0;
            for(int j = 0; j < 7; j++) {
                int day = (startday - 1 + j) % 7;
                // skip
                if(day == 5 || day == 6) continue;
				if(timelogs[i][j] <= limit) {
                   cnt++; 
                }
            }
            
            if(cnt == 5) {
                res++;
            }
        }
        return res;
    }
}