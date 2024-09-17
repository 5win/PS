import java.util.*;
import java.util.stream.*;

class Solution {
   	static Map<String, Integer> map = new HashMap<>(); 
    static int[][] arr = new int[51][51];
    static int[] point = new int[51];
    static int[] cnt = new int[51];
    static int n;
    
    static void solve() {
       	for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if(arr[i][j] > arr[j][i]) {
                   	cnt[i]++; 
                } else if(arr[i][j] == arr[j][i] && point[i] > point[j]) {
                  	cnt[i]++; 
                }
            }
        }
    }
    
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        n = friends.length;
        
       	for (int i = 0; i < n; i++) {
            map.put(friends[i], i);
        } 
        
        for (int i = 0; i < gifts.length; i++) {
            String[] tmp = gifts[i].split(" ");
            int idx1 = map.get(tmp[0]);
            int idx2 = map.get(tmp[1]);
           	
            arr[idx1][idx2]++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
              	point[i] += arr[i][j];
                point[i] -= arr[j][i];
            }
            
        }
        solve();
        
        answer = Arrays.stream(cnt).max().getAsInt();
        
        return answer;
    }
}