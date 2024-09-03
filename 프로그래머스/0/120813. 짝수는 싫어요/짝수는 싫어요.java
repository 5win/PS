import java.util.*;

class Solution {
    public int[] solution(int n) {
		int[] answer = {};
       	
        List<Integer> arr = new ArrayList<>();
        for(int i = 1; i <= n; i += 2) {
            arr.add(i);
        }
        answer = arr.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}