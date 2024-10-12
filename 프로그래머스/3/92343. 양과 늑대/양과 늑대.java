import java.util.*;

class Solution {
   	
    class Node {
        int num;
        int wolf;
        int sheep;
        Set<Integer> set;
        
        public Node(int a, int b, int c, Set<Integer> d) {
           	num = a;
            wolf = b;
            sheep = c;
            set = d;
        }
    }
    
    int n;
    int[][] adj;
    
    public int solution(int[] info, int[][] edges) {
        int answer = 0;
       	n = info.length;
        adj = new int[n][n];
        
        for(int[] edge : edges) {
            adj[edge[0]][edge[1]] = 1;
        }
        
        Set<Integer> initSet = new HashSet<>();
        for(int i = 1; i < n; i++) {
       		if(adj[0][i] == 1)    
                initSet.add(i);
        }
        
        Node root;
       	if(info[0] == 0) 
        	root = new Node(0, 0, 1, initSet);
        else
            root = new Node(0, 1, 0, initSet);
        
       	Queue<Node> q = new LinkedList<>();
        q.offer(root);
        
        int maxSheep = 0;
        
        while(!q.isEmpty()) {
            Node cnode = q.poll();
            int here = cnode.num;
            Set<Integer> set = cnode.set;
            int wolf = cnode.wolf;
            int sheep = cnode.sheep;
            maxSheep = Math.max(maxSheep, sheep);
            
            for(int next : set) {
                if(info[next] == 0) {
                    Set<Integer> nset = new HashSet<>(set);
                    nset.remove(next);
                    for(int j = 0; j < n; j++)
                        if(adj[next][j] == 1)
                            nset.add(j);
                    q.offer(new Node(next, wolf, sheep + 1, nset));
                } else if(wolf + 1 < sheep) {
                    Set<Integer> nset = new HashSet<>(set);
                    nset.remove(next);
                    for(int j = 0; j < n; j++)
                        if(adj[next][j] == 1)
                            nset.add(j);
                    q.offer(new Node(next, wolf + 1, sheep, nset));
                }
            }
        }
        
        
        return maxSheep;
    }
}