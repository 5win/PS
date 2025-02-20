import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        
        boolean[] visited = new boolean[1000001];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, 0});
        visited[x] = true;
        
        while(!q.isEmpty()) {
            int[] here = q.poll();
            int num = here[0];
            int dist = here[1];
            if(num == y) {
                return dist;
            } else if(num > y) {
                continue;
            }
            
           	if(num + n <= 1000000 && !visited[num + n]) {
                visited[num + n] = true;
            	q.offer(new int[]{num + n, dist + 1});
            }
            if(num * 2 <= 1000000 && !visited[num * 2]) {
                visited[num * 2] = true;
            	q.offer(new int[]{num * 2, dist + 1});
            }
            if(num * 3 <= 1000000 && !visited[num * 3]) {
                visited[num * 3] = true;
            	q.offer(new int[]{num * 3, dist + 1});
            }
        }
        
        return -1;
    }
}