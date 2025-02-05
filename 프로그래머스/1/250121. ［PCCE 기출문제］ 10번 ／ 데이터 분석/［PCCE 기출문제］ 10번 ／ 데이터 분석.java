import java.util.*;

class Solution {
    public int convertExt(String ext) {
       	if(ext.equals("code")) {
            return 0;
        } else if(ext.equals("date")) {
           	return 1; 
        } else if(ext.equals("maximum")) {
           	return 2; 
        }
        return 3; 
    }
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        
        List<int[]> filtered = new ArrayList<>();
        int target = convertExt(ext);
        int idx = 0;
        for(int[] d : data) {
           	if(d[target] < val_ext) {
                filtered.add(d);
            }
        }
        
        int sortBy = convertExt(sort_by);
        Collections.sort(filtered, (a, b) -> a[sortBy] - b[sortBy]);
       	
        int[][] res = new int[filtered.size()][4];
        for(int i = 0; i < filtered.size(); i++) {
            res[i] = filtered.get(i);
        }
        return res;
    }
}