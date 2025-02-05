import java.util.*;

class Solution {
	List<String> exts;
    
    public int convertExt(String ext) {
        return exts.indexOf(ext);
    }
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        String[] extArray = {"code", "date", "maximum", "remain"};
       	exts = Arrays.asList(extArray);
        
        int target = convertExt(ext);
        int sortBy = convertExt(sort_by);
        
        return Arrays.stream(data)
            .filter(d -> d[target] < val_ext)
            .sorted((a, b) -> a[sortBy] - b[sortBy])
            .toArray(int[][]::new);
    }
}