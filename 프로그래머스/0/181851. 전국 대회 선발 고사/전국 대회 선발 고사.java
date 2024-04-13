import java.util.*;

class Solution {
    public int solution(int[] rank, boolean[] attendance) {
       	TreeMap<Integer, Integer> tm = new TreeMap<>();
        for(int i = 0; i < rank.length; i++) {
            if(attendance[i])
                tm.put(rank[i], i);
        }
        ArrayList<Integer> arr = new ArrayList<>();
        for(Integer i : tm.keySet()) {
            arr.add(tm.get(i));
        }
        return 10000 * arr.get(0) + 100 * arr.get(1) + arr.get(2);
    }
}