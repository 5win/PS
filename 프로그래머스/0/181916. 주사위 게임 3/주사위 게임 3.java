import java.util.*;

class Solution {
    int[] cnt = new int[7];
    List<Integer>[] lst = new List[5];
    
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        for(int i = 0; i <= 4; i++) {
            lst[i] = new ArrayList<>();
        }
        
        cnt[a]++; cnt[b]++; cnt[c]++; cnt[d]++;
        
        for(int i = 1; i <= 6; i++) {
            if(cnt[i] != 0) {
                lst[cnt[i]].add(i);
            }
        }
       	
        if(!lst[4].isEmpty()) {
           	answer = 1111 * lst[4].get(0); 
        } else if(!lst[3].isEmpty()) {
            int tmp = 10 * lst[3].get(0) + lst[1].get(0);
            answer = tmp * tmp;
        } else if(lst[2].size() == 2) {
            int p = lst[2].get(0);
            int q = lst[2].get(1);
            answer = (p + q) * Math.abs(p - q);
        } else if(lst[2].size() == 1) {
            int q = lst[1].get(0), r = lst[1].get(1);
            answer = q * r;
        } else {
            answer = Collections.min(lst[1]);
        }
        
        return answer;
    }
}