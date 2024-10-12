import java.util.*;

class Solution {
    
    int[][] res;
    int[][] board;
    int n, m;
    
   	void update(int r1, int c1, int r2, int c2, int amount) {
        r1++; c1++; r2++; c2++;
        
    	board[r1][c1] -= amount;
        board[r1][c2 + 1] += amount;
       	board[r2 + 1][c1] += amount;
        board[r2 + 1][c2 + 1] -= amount;
    } 
    
    void psum() {
        for(int i = 1; i <= n; i++) 
           	for(int j = 2; j <= m; j++) 
                board[i][j] += board[i][j - 1];
        
		for(int j = 1; j <= m; j++)
        	for(int i = 2; i <= n; i++) 
                board[i][j] += board[i - 1][j];
        
        for(int i = 1; i <= n; i++) 
           	for(int j = 1; j <= m; j++) 
                res[i][j] += board[i][j];
    }
    
    int calcCnt() {
        int ret = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(res[i][j] > 0) ret++;
            }
        }
        return ret;
    }
    
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        n = board.length;
        m = board[0].length;
        
        this.board = new int[n + 2][m + 2];
        res = new int[n + 2][m + 2];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res[i + 1][j + 1] = board[i][j];
        
       	
        for(int[] arr : skill) {
            if(arr[0] == 1) {
               	update(arr[1], arr[2], arr[3], arr[4], arr[5]);
            } else {
               	update(arr[1], arr[2], arr[3], arr[4], -arr[5]);
            }
        }
        psum();
       	answer = calcCnt(); 
        
        return answer;
    }
}