class Solution {
    
    String one = "11011";
    String zero = "00000";
    
    long l, r;
    int cnt = 0;
    boolean start = false;
    boolean finish = false;
    
    public void dfs(int n, int prev, long p) {
        if(finish) {
            return;
        }
        
        if(n == 0) {
            if(p == r) {
                finish = true;
            }
            
            if(p == l) {
				start = true; 
            }
            
            if(start) {
                //System.out.println(prev + ", " + p);
                cnt = prev == 0 ? cnt : cnt + 1;
                return;
            }
            return;
        }
       	
        long perCnt = (long) Math.pow(5, n - 1);
        for(int i = 0; i < 5; i++) {
            long curP = p + perCnt * i;
            //System.out.println(curP);
            if(curP + perCnt <= l) {
                continue;
            } else {
                if(prev == 1) {
                    //int nextNum = i == 0 ? 1 : one.charAt(i - 1) - '0';
                    //long nextP = i == 0 ? curP : curP - perCnt;
                	dfs(n - 1, one.charAt(i) - '0', curP);
                	//dfs(n - 1, nextNum, nextP);
                } else {
                   	dfs(n - 1, 0, curP); 
                }
            }
        }
    }
    
    public int solution(int n, long l, long r) {
        l--; r--;
        
        this.l = l;
        this.r = r;
        
        dfs(n, 1, 0);
        
        return cnt;
    }
}