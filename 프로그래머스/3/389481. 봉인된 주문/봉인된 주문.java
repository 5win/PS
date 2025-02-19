import java.util.*;

class Solution {
    long n;
    String[] bans;
    long[] banNums;
    
    public void convertToNum() {
        banNums = new long[bans.length];
        
       	for(int i = 0; i < bans.length; i++) {
            char[] cur = bans[i].toCharArray();
            long num = 0;
            for(int j = 0; j < cur.length; j++) {
                long p = 1;
                for(int k = 0; k < cur.length - 1 - j; k++) {
                   	p *= 26; 
                }
                //num += (cur[j] - 'a' + 1) * (long)Math.pow(26, (long)cur.length - 1 - j);
                num += (cur[j] - 'a' + 1) * p;
            }
            banNums[i] = num;
        } 
        Arrays.sort(banNums);
    }
    
    
    public String convertToString() {
        StringBuilder sb = new StringBuilder();
        
        long div = 26;
        long num = n;
        while(num > 0) {
            sb.append((char)(num % div + 'a'));
            num /= div;
            num--;
        }
        if(num == 0) {
            sb.append((char)(num % div + 'a'));
        }
        return sb.reverse().toString();
    }
    
    public String solution(long n, String[] bans) {
        this.n = n;
        this.bans = bans;
        
        convertToNum();
        
       	// move number 
        for(int i = 0; i < banNums.length; i++) {
            long cur = banNums[i];
            //System.out.println(cur);
            if(cur <= this.n) {
                this.n++;
            }
        }
        this.n--;
        
        // convert to string
        String res = convertToString();
        return res;
    }
}