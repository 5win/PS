import java.util.*;

class Solution {
    
    class Node implements Comparable<Node> {
        int fir;
        long sec;
        public Node(int a, long b) {
            fir = a;
            sec = b;
        }
        public int compareTo(Node o) {
            return Long.compare(sec, o.sec);
        }
    }
   
    static final long INF = Long.MAX_VALUE;
    int n;
    int[][] paths;
    int[] gates;
    int[] summits;
    boolean[] isSummit;
    List<Node>[] adj;
    int[] res;
    
    long[] dijkstra(int limit) {
       	PriorityQueue<Node> pq = new PriorityQueue<>();
        long[] dist = new long[n + 1];
        Arrays.fill(dist, INF);
        
        for(int i = 0; i < gates.length; i++) {
            pq.offer(new Node(gates[i], 0));
            dist[gates[i]] = 0;
        }
        
        while(!pq.isEmpty()) {
            Node cnode = pq.poll();
            int here = cnode.fir;
            long cost = cnode.sec;
            
            if(dist[here] < cost) continue;
            for(Node i : adj[here]) {
                int next = i.fir;
                long nc = cost + i.sec;
                if(dist[next] <= nc || i.sec > limit) continue;
                
                dist[next] = nc;
                if(isSummit[next]) continue;
                pq.offer(new Node(next, nc));
            }
        }
        return dist;
    }
    
    void binarySearch() {
       	int s = 0, e = (int)1e7 + 1; 
        while(s + 1 < e) {
    		int mid = (s + e) / 2;
            long[] dist = dijkstra(mid);
           	boolean flag = false; 
            for(int sNum : summits) {
                if(dist[sNum] != INF) {
					res = new int[]{sNum, mid}; 
                    flag = true;
                    break;
                }
            }
           	if(flag) {
               	e = mid; 
            } else {
                s = mid;
            }
        }
    }
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        int[] answer = {};
        
        this.n = n;
        this.paths = paths;
        this.gates = gates;
        this.summits = summits;
        isSummit = new boolean[n + 1];
        adj = new List[n + 1];
        
        for(int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();
        
        for(int i = 0; i < paths.length; i++) {
           	int src = paths[i][0];
            int dst = paths[i][1];
            long cost = paths[i][2];
            adj[src].add(new Node(dst, cost));
            adj[dst].add(new Node(src, cost));
        }
        
        Arrays.sort(summits);
       	for(int i : summits)
            isSummit[i] = true;
        
        binarySearch();
        
        
        return answer = res;
    }
}