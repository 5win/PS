import java.util.*;

class Solution {
	
    int res = -1;
    int n;
    int[] info;
    int[] visited = new int[11];
    int[] path;
    
    void dfs(int remain, int num, int score, int score2) {
        
        if(num == 11) {
            if(score > score2) {
                if(res < score - score2) {
                    res = Math.max(res, score - score2);
                    path = visited.clone();
                } else if(res == score - score2) {
                   	for(int i = 10; i >= 0; i--) {
                        if(visited[i] > path[i]) {
                           	path = visited.clone(); 
                            break;
                        } else if(visited[i] < path[i]) {
                           	break; 
                        }
                    } 
                }
            }
            return;
        }
        
        if(num == 10) {
            visited[num] = remain;
            dfs(0, num + 1, score, score2);
            visited[num] = 0;
            return;
        }
        
        int cost = 10 - num;
        if(info[num] == 0) {
           	dfs(remain, num + 1, score, score2); 
            if(remain > 0) {
                visited[num] = 1;
                dfs(remain - 1, num + 1, score + cost, score2);
                visited[num] = 0;
            }
        } else {
           	dfs(remain, num + 1, score, score2 + cost);
            if(remain >= info[num] + 1) {
            	visited[num] = info[num] + 1;
            	dfs(remain - info[num] - 1, num + 1, score + cost, score2);
            	visited[num] = 0;
            }
        }
    }
    
    public int[] solution(int n, int[] info) {
        int[] answer = {};
        this.n = n;
        this.info = info;
        
       	dfs(n, 0, 0, 0); 
       	if(res == -1)
            return new int[]{-1};
        
        answer = new int[11];
        for(int i = 0; i < 10; i++) {
            if(path[i] > 0) {
                answer[i] = info[i] + 1;
            }
        }
        answer[10] = path[10];
        return answer;
    }
}