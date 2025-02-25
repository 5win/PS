import java.util.*;

class Solution {
    
    int n;
    int[] nodes;
    Map<Integer, List<Integer>> adj = new HashMap<>();
    
    public int traverse(int parent, int here, boolean isRoot, int pState) {
        
        
        int childCnt = adj.get(here).size();
        if(childCnt != 0 && !isRoot) {
            childCnt--;
        }
        
        int curState = here % 2 == 0 ? (childCnt % 2 == 0 ? 1 : 2) : (childCnt % 2 == 0 ?2 : 1);
        
        // 부모와 상태가 다르면 바로 반환
        if(!isRoot && pState != curState) {
            return 0;
        }
        
    	for(int child : adj.get(here)) {
            if(child == parent) continue;
            int childState = traverse(here, child, false, curState);
            
            if(childState == 0) {
                return 0;
            }
           	
            if(curState != childState) {
                return 0;
            }
        } 
        return curState;
    }
    
    public int[] solution(int[] nodes, int[][] edges) {
        n = nodes.length;
        this.nodes = nodes;
        
        
        // init edges
        for(int node : nodes) {
            adj.put(node, new ArrayList<>());
        }
        for(int[] edge : edges) {
            List<Integer> list1 = adj.getOrDefault(edge[0], new ArrayList<>());
            List<Integer> list2 = adj.getOrDefault(edge[1], new ArrayList<>());
            list1.add(edge[1]);
            list2.add(edge[0]);
            adj.put(edge[0], list1);
            adj.put(edge[1], list2);
        }
        
        // logic
        int cnt1 = 0, cnt2 = 0;
        for(int node : nodes) {
            int childState = traverse(-1, node, true, -1);
            if(childState == 1) {
                cnt1++;
            } else if(childState == 2) {
                System.out.println(node);
                cnt2++;
            }
        }
        return new int[]{cnt1, cnt2};
    }
}