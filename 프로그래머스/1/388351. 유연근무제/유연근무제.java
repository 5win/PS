class Solution {
    
    public int plusTenMin(int t) {
       	int h = t / 100;
        int m = t % 100;
        m += 10;
        
        if(m >= 60) {
            h++;
            m %= 60;
        }
        return h * 100 + m;
    }
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        
        int ans = 0;
        
       	for(int i = 0; i < schedules.length; i++) {
           	int limit = plusTenMin(schedules[i]);
            int cnt = 0;
           	for(int j = 0; j < 7; j++) {
                int day = (startday - 1 + j) % 7;
                if(day == 5 || day == 6) continue;
                if(timelogs[i][j] <= limit) {
                   	cnt++; 
                }
            } 
            if(cnt == 5) {
               	ans++; 
            }
        } 
        return ans;
    }
}