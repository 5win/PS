import java.util.*;

class Solution {
    
   	String makeKBase(int n, int k) {
       	StringBuilder sb = new StringBuilder();	
        
        while(n > 0) {
            int a = n / k;
            int b = n % k;
           	sb.append(String.valueOf(b));
            n = a;
        }
       	return sb.reverse().toString(); 
    } 
    
    public boolean isPrime(long num) {
        if(num == 1) return false;
       	for(long i = 3; i <= Math.sqrt(num); i++) {
           	if(num % i == 0) return false; 
        }
       	return true; 
    }
    
    public int solution(int n, int k) {
        int answer = -1;
        
		String base = makeKBase(n, k);
        String[] nums = base.split("0");
        
        answer = 0;
        
         for(String s : nums) {
             if(s.equals("")) continue;
             long num = Long.parseLong(s);
             if(isPrime(num))
                 answer++;
         }
       
        
        return answer;
    }
}