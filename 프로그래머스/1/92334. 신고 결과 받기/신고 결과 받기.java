import java.util.*;

class Solution {
    
    Set<String> reportLog = new HashSet<>();
    Map<String, Integer> reportCnt = new HashMap<>();
    Map<String, Integer> mail = new HashMap<>();
    Map<String, List<String>> rMap = new HashMap<>();
    
    
    public int[] solution(String[] id_list, String[] report, int k) {
        
		for(String s : report)
            reportLog.add(s);
        
        for(String rep : reportLog) {
            String[] tmp = rep.split(" ");
            String src = tmp[0], dst = tmp[1];
           	reportCnt.put(dst, reportCnt.getOrDefault(dst, 0) + 1); 
            List<String> sender = rMap.getOrDefault(dst, new ArrayList<>());
            sender.add(src);
            rMap.put(dst, sender);
        }
        
       	for(Map.Entry<String, Integer> e : reportCnt.entrySet()) {
           	if(e.getValue() >= k) {
                List<String> list = rMap.get(e.getKey());
                for(String recv : list) 
                	mail.put(recv, mail.getOrDefault(recv, 0) + 1);
            }
        } 
        
        int[] answer = new int[id_list.length];
        for(int i = 0; i < id_list.length; i++) {
            answer[i] = mail.getOrDefault(id_list[i], 0);
        }
        return answer;
    }
}