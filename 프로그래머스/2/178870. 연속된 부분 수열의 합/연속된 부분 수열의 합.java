class Solution {
    int n;
    
    public int[] solution(int[] seq, int k) {
        n = seq.length;
        
        int[] res = {0, 1987654321};
        
        int sum = 0;
        int e = 0;
        for(int s = 0; s < n; s++) {
           	while(e < n && sum < k) {
               	sum += seq[e++];
            } 
            if(sum == k && e - s < res[1] - res[0]) {
               	res[0] = s;
                res[1] = e;
            }
            sum -= seq[s];
        }
        
        res[1]--;
        return res;
    }
}