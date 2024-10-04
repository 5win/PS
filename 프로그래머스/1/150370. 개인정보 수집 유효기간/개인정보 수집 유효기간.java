import java.util.*;


class Solution {
    static int tDate;
   	static Map<String, Integer> map = new HashMap<>(); 
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        
       	List<Integer> res = new ArrayList<>(); 
        
        tDate = Integer.parseInt(today.replaceAll("\\.", ""));
        
        for(int i = 0; i < terms.length; i++) {
            String[] input = terms[i].split(" ");
            map.put(input[0], Integer.parseInt(input[1]));
        }
        
        int cnt = 1;
        for(String p : privacies) {
            String[] input = p.split(" ");
            int amount = map.get(input[1]);
            int date = Integer.parseInt(input[0].replaceAll("\\.", ""));
            
            int month = ((date % 10000) / 100) - 1 + amount;
            int addYear = date / 10000 + (month / 12);
            int addMonth = month % 12 + 1;
            
            date = addYear * 10000 + addMonth * 100 + (date % 100);
            
            if(date <= tDate) 
                res.add(cnt);
           
            cnt++;
        }
        
        
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}