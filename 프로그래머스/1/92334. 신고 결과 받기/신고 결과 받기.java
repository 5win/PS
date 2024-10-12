import java.util.*;

class Solution {
    
   	Map<String, Integer> id = new HashMap<>();
    int[] reported;
    Set<Integer>[] reporter;
    
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = {};
        
        int idx = 0;
       	for(int i = 0; i < id_list.length; i++) {
            if(id.containsKey(id_list[i])) continue;
            id.put(id_list[i], idx++);
        } 
        
        reported = new int[idx];
        reporter = new HashSet[idx];
        for(int i = 0; i < idx; i++) {
            reporter[i] = new HashSet<>();
        }
        
        for(String str : report) {
           	String[] input = str.split(" ");
            int id1 = id.get(input[0]);
            int id2 = id.get(input[1]);
            if(reporter[id2].contains(id1)) continue;
           	reported[id2]++;
            reporter[id2].add(id1);
        }
        
        int[] cnt = new int[idx];
        for(int i = 0; i < reported.length; i++) {
            if(reported[i] >= k) {
                for(int j : reporter[i]) {
                    cnt[j]++;
                }
            }
        }
        
        return answer = cnt;
    }
}