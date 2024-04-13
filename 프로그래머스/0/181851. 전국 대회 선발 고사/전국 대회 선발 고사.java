import java.util.*;

public class Tuple {
	public int x;
    public int y;
    
   	Tuple(int x, int y) {
        this.x = x;
        this.y = y;
    } 
}

class TupleComparator implements Comparator<Tuple> {
    @Override
    public int compare(Tuple o1, Tuple o2) {
        return o1.x - o2.x;
    }
}

class Solution {
    public static Comparator<Tuple> comp = new Comparator<Tuple>() {
     	@Override
        public int compare(Tuple o1, Tuple o2) {
          	return o1.x - o2.x;
        }
    };
    
    
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        
        List<Tuple> canAttend = new ArrayList<>();
        for(int i = 0; i < rank.length; i++) {
            if(attendance[i])
                canAttend.add(new Tuple(rank[i], i));
        }
        Collections.sort(canAttend, new TupleComparator());
        answer += 10000 * canAttend.get(0).y;
        answer += 100 * canAttend.get(1).y;
        answer += canAttend.get(2).y;
        
        return answer;
    }
}