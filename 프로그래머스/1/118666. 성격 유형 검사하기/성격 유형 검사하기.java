import java.util.*;

class Solution {
    
    Map<Character, Integer> map = new HashMap<>();
    int n;
    
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        n = survey.length;
   	
        for(int i = 0; i < n; i++) {
            int score = choices[i];
           	
            char fir = survey[i].charAt(0);
            char sec = survey[i].charAt(1);
            
           	int tmp; 
            if(score < 4) {
                tmp = map.getOrDefault(fir, 0);
                map.put(fir, 4 - score + tmp);
            } else if(score > 4) {
               	tmp = map.getOrDefault(sec, 0);
                map.put(sec, score - 4 + tmp);
            }
        }
        
       	int one = map.getOrDefault('R', 0);
        int two = map.getOrDefault('T', 0);
        if(one >= two) answer += "R";
        else answer += "T";
        
       	one = map.getOrDefault('C', 0);
        two = map.getOrDefault('F', 0);
        if(one >= two) answer += "C";
        else answer += "F";
       	 
       	one = map.getOrDefault('J', 0);
        two = map.getOrDefault('M', 0);
        if(one >= two) answer += "J";
        else answer += "M";
        
       	one = map.getOrDefault('A', 0);
        two = map.getOrDefault('N', 0);
        if(one >= two) answer += "A";
        else answer += "N";
        
        return answer;
    }
}