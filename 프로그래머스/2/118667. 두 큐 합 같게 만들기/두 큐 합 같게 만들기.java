import java.util.*;

class Solution {
    
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        
       	Queue<Long> q1 = new LinkedList<>(); 
       	Queue<Long> q2 = new LinkedList<>(); 
        
        long sum1 = 0, sum2 = 0;
        for(int i = 0; i < queue1.length; i++) {
            sum1 += (long)queue1[i];
            q1.offer((long)queue1[i]);
        }
        for(int i = 0; i < queue2.length; i++) {
            sum2 += (long)queue2[i];
            q2.offer((long)queue2[i]);
        }
        
        int n = q1.size() + q2.size();
        long num;
        for(int i = 0; i < 2 * n; i++) {
            if(sum1 > sum2) {
                num = q1.poll();
               	q2.offer(num);
                sum1 -= num;
                sum2 += num;
            } else if(sum1 < sum2) {
                num = q2.poll();
               	q1.offer(num);
                sum1 += num;
                sum2 -= num;
            } else {
               	answer = i; 
                break;
            }
        }
        
        return answer;
    }
}