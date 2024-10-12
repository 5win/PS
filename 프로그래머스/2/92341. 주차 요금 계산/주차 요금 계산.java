import java.util.*;

class Solution {
    
   	Map<Integer, Integer> time = new HashMap<>();
    int[] res = new int[10000];
    boolean[] visited = new boolean[10000];
    
    int convertTime(String t) {
        String[] times = t.split(":");
        return Integer.parseInt(times[0]) * 60 + Integer.parseInt(times[1]);
    }
    
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        
        int baseTime = fees[0];
        int baseFee = fees[1];
        int unitTime = fees[2];
        int unitFee = fees[3];
       	
        for(String str : records) {
            String[] s = str.split(" ");
            int t = convertTime(s[0]);
            int num = Integer.parseInt(s[1]);
            visited[num] = true;
            
            if(s[2].equals("IN")) {
               	time.put(num, t); 
            } else {
               	int stime = time.get(num); 
                time.remove(num);
                res[num] += t - stime;
            }
        }
        int endTime = convertTime("23:59");
        for(Map.Entry<Integer, Integer> e : time.entrySet()) {
            res[e.getKey()] += endTime - e.getValue();
        }
       	
        
        List<Integer> tmp = new ArrayList<>();
        for(int i = 0; i < 10000; i++) {
            if(visited[i]) {
                int fee = baseFee;
                int extraTime = res[i] - baseTime;
                if(extraTime > 0) {
                    fee += unitFee * ((extraTime + unitTime - 1) / unitTime);
                } 
                tmp.add(fee);
            }
        }
        
        return tmp.stream().mapToInt(v -> v).toArray();
    }
}