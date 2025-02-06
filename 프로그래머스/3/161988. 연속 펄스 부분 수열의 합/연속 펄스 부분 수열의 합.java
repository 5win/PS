class Solution {
    public long solution(int[] seq) {
        
        // start 1
        long[] res1 = new long[seq.length];
        long max1 = seq[0];
        res1[0] = seq[0];
        for(int i = 1; i < seq.length; i++) {
            long curSeq = i % 2 == 0 ? seq[i] : -seq[i];
           	res1[i] = Math.max(res1[i - 1] + curSeq, curSeq); 
            max1 = Math.max(max1, res1[i]);
        }
        
        // start -1
        long[] res2 = new long[seq.length];
        long max2 = -seq[0];
        res2[0] = -seq[0];
        for(int i = 1; i < seq.length; i++) {
            long curSeq = i % 2 == 1 ? seq[i] : -seq[i];
           	res2[i] = Math.max(res2[i - 1] + curSeq, curSeq); 
            max2 = Math.max(max2, res2[i]);
        }
        
       	return Math.max(max1, max2); 
    }
}