class Solution {
    
    int n, cap;
    int[] psum1, psum2;
    int[] deli, pick;
    
    void calcPsum() {
        psum1[n - 1] = deli[n - 1];
        psum2[n - 1] = pick[n - 1];
       	for(int i = n - 2; i >= 0; i--) {
            psum1[i] += psum1[i + 1] + deli[i];
            psum2[i] += psum2[i + 1] + pick[i];
        }
    }
    
    long solve() {
        
        long ret = 0;
        int deliSum = 0, pickSum = 0;
        int end = n;
        int i = n - 1;
       	while(i >=0 && psum1[i] == 0 && psum2[i] == 0) {
            end--;
            i--; 
        }
        
        while(i >= 0) {
           	if(psum1[i] - deliSum <= cap && psum2[i] - pickSum <= cap) {
                i--;
                continue;
            }
           	deliSum += cap;
            pickSum += cap;
            ret += end * 2;
            end = i + 1;
        }
        ret += end * 2;
        return ret;
    }
        
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = -1;
        this.n = n;
        this.cap = cap;
       	psum1 = new int[n]; 
       	psum2 = new int[n]; 
        deli = deliveries;
        pick = pickups;
       	 
        calcPsum();
        answer = solve();
        
        return answer;
    }
}