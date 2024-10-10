import java.util.*;

class Solution {
    
    String makeString(long num) {
       	StringBuilder sb = new StringBuilder(); 
        while(num > 0) {
            if((num & 1) > 0) {
                sb.append('1');
            } else {
                sb.append('0');
            }
            num = num >> 1;
        }
        
    	int len = sb.length();
        int k = 1;
        while(len > k) {
            k = (k << 1) | 1;
        }
       	while(len < k) {
            sb.append('0');
            len++;
        }
        
       	return sb.reverse().toString();
    }
    
    boolean dfs(String here) {
        if(here.length()  <= 1) return true;
        int mid = here.length() / 2;
       	if(here.charAt(mid) == '0') {
           	for(int i = 0; i < here.length(); i++) {
                if(i == mid) continue;
                if(here.charAt(i) == '1')
                    return false;
            } 
            return true;
        } else {
           	return dfs(here.substring(0, mid)) && dfs(here.substring(mid + 1, here.length()));
        }
    }
    
    public int[] solution(long[] numbers) {
        int[] answer = {};
       	
        List<Integer> lst = new ArrayList<>();
        for(long num : numbers) {
       		String str = makeString(num);
            boolean res = dfs(str);
            if(res)
                lst.add(1);
            else
                lst.add(0);
        }
        answer = lst.stream().mapToInt(v -> v).toArray();
        
        return answer;
    }
}