import java.util.*;

class Plan {
    String name;
    int start;
    int len;
    
    public Plan(String a, int b, int c) {
        name = a;
        start = b;
        len = c;
    }
}

class Solution {
    
    List<Plan> seq = new ArrayList<>();
    
    public int convertToSec(String time) {
        String[] parsed = time.split(":");
        return Integer.parseInt(parsed[0]) * 3600 + Integer.parseInt(parsed[1]) * 60;
    }
    
    public String[] solution(String[][] plans) {
        
		for(String[] p : plans) {
            int start = convertToSec(p[1]);
            int len = Integer.parseInt(p[2]) * 60;
            seq.add(new Plan(p[0], start, len));
        } 
        Collections.sort(seq, (a, b) -> a.start - b.start);
        
       	// 과제 시작 
        
        List<String> res = new ArrayList<>();
        Stack<Plan> st = new Stack<>();
        
        int limit = convertToSec("2000:00");
        int pIdx = 0;
        for(int i = seq.get(0).start; i <= limit; i++) {
            // do plan and is finish?
            if(!st.isEmpty()) {
                Plan prev = st.peek();
                prev.len--;
                if(prev.len == 0) {
                    res.add(st.peek().name);
                    st.pop();
                }
            }
            
            // new plan
            if(pIdx < seq.size() && seq.get(pIdx).start == i) {
				st.push(seq.get(pIdx));
				pIdx++;
            } 
        }
   		return res.stream().toArray(String[]::new);         
    }
}