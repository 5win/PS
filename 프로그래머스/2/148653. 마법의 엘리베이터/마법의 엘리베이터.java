import java.util.*;

class Solution {
    
    public int solution(int storey) {
        
        int res = 0;
        int div = 10;
        while(storey != 0) {
           	int remain = storey % div;
            if(remain < 5) {
               	storey -= remain; 
                res += remain;
            } else if(remain > 5) {
               	storey += 10 - remain; 
                res += 10 - remain;
            } else {
                int nRemain = (storey / div) % div;
                if(nRemain < 5) {
                  	storey -= remain; 
                    res += remain;
                } else {
                    storey += 10 - remain;
                    res += 10 - remain;
                }
            }
            storey /= div;
        }
       	return res; 
    }
}