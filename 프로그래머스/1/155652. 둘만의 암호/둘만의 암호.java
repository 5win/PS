class Solution {
    public String solution(String s, String skip, int index) {
        
        StringBuilder sb = new StringBuilder();
        
        for(char c : s.toCharArray()) {
            char cur = c;
            for(int i = 0; i < index;) {
               	cur = cur == 'z' ? 'a' : (char)(cur + 1); 
            	if(skip.indexOf(cur) >= 0) continue;
                i++;
            }
           	sb.append(cur); 
        }
        
        return sb.toString();
    }
}