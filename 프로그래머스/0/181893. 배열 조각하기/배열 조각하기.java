import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int[] arr, int[] query) {
        
        List<Integer> answer = Arrays.stream(arr).boxed().collect(Collectors.toList());
        for(int i = 0; i < query.length; i++) {
            if(i % 2 == 0) {
               	answer = new ArrayList<>(answer.subList(0, query[i] + 1));
            } else {
               	answer = new ArrayList<>(answer.subList(query[i], answer.size()));
            }
        }
        int[] ret = answer.stream().mapToInt(Integer::intValue).toArray();
        
        return ret;
    }
}