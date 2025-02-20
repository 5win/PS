import java.util.*;

class Solution {
    
    Map<Character, Integer> keys = new HashMap<>();
    public int[] solution(String[] keymap, String[] targets) {
        
        // make key index map
        for(String key : keymap) {
            char[] s = key.toCharArray();
            for(int i = 0; i < s.length; i++) {
                int idx = keys.getOrDefault(s[i], Integer.MAX_VALUE);
                if(i < idx) {
                    keys.put(s[i], i);
                }
            }
        }
        
        // calc result
        int[] res = new int[targets.length];
        int index = 0;
        for(String s : targets) {
            int sum = 0;
            for(char c : s.toCharArray()) {
				sum += keys.getOrDefault(c, 99999) + 1;
            }
            res[index] = sum >= 99999 ? -1 : sum;
            index++;
        }
        return res;
    }
}