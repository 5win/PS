import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        
        List<int[]> list = new ArrayList<>();
        for(int i = 0; i < targets.length; i++) {
            list.add(new int[]{targets[i][0], 1, i});
            list.add(new int[]{targets[i][1], -1, i});
        }
        Collections.sort(list, (a, b) -> {
           	if(a[0] == b[0]) {
                return a[1] - b[1];
            } 
            return a[0] - b[0];
        });
        
        int res = 0;
        int curSize = 0;
        Set<Integer> willDelete = new HashSet<>();
        Set<Integer> deleted = new HashSet<>();
        for(int i = 0; i < list.size(); i++) {
       		int[] here = list.get(i);
            if(here[1] == -1 && !deleted.contains(here[2])) {
                res++;
                deleted.addAll(willDelete);
                willDelete.clear();
            } else {
                willDelete.add(here[2]);
            }
        }
        return res;
    }
}