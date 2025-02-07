import java.util.*;

class Solution {
    
    public int convertToMin(String t) {
        String[] time = t.split(":");
        return Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
    }
    public int solution(String[][] book_time) {
        
       	List<int[]> times = new ArrayList<>();
        for(String[] book : book_time) {
           	int s = convertToMin(book[0]); 
           	int e = convertToMin(book[1]) + 10; 
            times.add(new int[]{s, 1});
            times.add(new int[]{e, -1});
        }
        
        Collections.sort(times, (a, b) -> {
          	if(a[0] == b[0]) {
                return a[1] - b[1];
            }  
            return a[0] - b[0];
        });
        
        // +1, -1
        int sum = 0;
        int max = 0;
        int limit = convertToMin("24:00");
        int idx = 0;
        for(int i = 0; i < limit; i++) {
            if(idx == times.size()) break;
            while(idx < times.size() && times.get(idx)[0] == i) {
                sum += times.get(idx)[1];
                max = Math.max(max, sum);
                idx++;
            }
		}
        return max;
    }
}