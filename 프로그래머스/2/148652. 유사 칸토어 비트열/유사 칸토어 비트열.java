class Solution {
    
    final String ONE = "11011";
    
    long l, r;
    int cnt = 0;
    boolean start = false;
    boolean finish = false;
    
    public void dfs(int n, int prev, long p) {
        if(finish) return;		// r까지 카운팅을 했으면, 무조건 return
        
        if(n == 0) {
            if(p == l) start = true; 
            if(p == r) finish = true;
            
            if(start) {
                cnt = prev == 0 ? cnt : cnt + 1;
            }
            return;
        }
       	
        long perCnt = (long) Math.pow(5, n - 1);
        for(int i = 0; i < 5; i++) {
            long curP = p + perCnt * i;
            long nextP = p + perCnt * (i + 1);
            if(nextP <= l) continue;	// 다음 브랜치가 l 존재 가능 범위이면, 현재 브랜치 skip
            
            if(prev == 1) {
                dfs(n - 1, ONE.charAt(i) - '0', curP);
            } else {
                dfs(n - 1, 0, curP); 	// 이전 숫자가 0이면, 무조건 0
            }
        }
    }
    
    public int solution(int n, long l, long r) {
        //l--; r--;	// 
        
        this.l = l;
        this.r = r;
        
        dfs(n, 1, 1);
        
        return cnt;
    }
}