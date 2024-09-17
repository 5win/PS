import java.util.*;

class Solution {
    
    static List<Integer>[] adj = new ArrayList[1000001];
    static List<Integer>[] radj = new ArrayList[1000001];
    
    public int[] solution(int[][] edges) {
        int[] answer = {0, 0, 0, 0};
        
        for(int i = 0; i < 1000001; i++) {
            adj[i] = new ArrayList<Integer>();
            radj[i] = new ArrayList<Integer>();
        }
       	
        int s = Integer.MAX_VALUE, e = 0;
        for(int i = 0; i < edges.length; i++) {
            int src = edges[i][0];
            int dst = edges[i][1];
            
            adj[src].add(dst);
            radj[dst].add(src);
            
            s = Math.min(s, src);
            s = Math.min(s, dst);
            
            e = Math.max(e, src);
            e = Math.max(e, dst);
        }
        
        int newNode = -1;
        for(int i = s; i <= e; i++) {
            if(adj[i].size() >= 2 && radj[i].size() == 0) {
                newNode = i;
            } else if(adj[i].size() >= 2) {
                answer[3]++;
            } else if(adj[i].size() == 0 && radj[i].size() > 0) {
                answer[2]++;
            }
        }
        
        answer[0] = newNode;
        int totalCnt = adj[newNode].size();
        answer[1] = totalCnt - answer[2] - answer[3];
        
        return answer;
    }
}