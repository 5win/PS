import java.util.*;

class Solution {
   	
    int[][] parent = new int[51][51];
    String[][] board = new String[51][51];
    
    int find(int r, int c) {
        int here = parent[r][c];
        if(here == r * 50 + c) return here;
        return parent[r][c] = find(here / 50, here % 50);
    }
    
    void merge(int r1, int c1, int r2, int c2) {
        int n1 = find(r1, c1);
        int n2 = find(r2, c2);
        if(n1 == n2) return;
        
        parent[n1 / 50][n1 % 50] = n2;
    }
   	
    void updateOne(int r, int c, String v) {
     	int node = find(r, c);
       	board[node / 50][node % 50] = v;
    }
    
    void updateAll(String v1, String v2) {
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) { 
                int num = find(i, j);
                int r = num / 50;
                int c = num % 50;
                if(board[r][c].equals(v1)) 
                	board[i][j] = v2;
            }
        }
    }
    
    void mergeCell(int r1, int c1, int r2, int c2) {
       	int n1 = find(r1, c1); 
       	int n2 = find(r2, c2); 
       	
        int pr1 = n1 / 50;
        int pc1 = n1 % 50;
        int pr2 = n2 / 50;
        int pc2 = n2 % 50;
        
        String s1 = board[pr1][pc1];
        String s2 = board[pr2][pc2];
        
        //if(s1.equals(s2)) return;
        
        if(s1.equals("EMPTY") && !s2.equals("EMPTY")) 
            board[pr1][pc1] = board[pr2][pc2] = s2;
        
        else if(!s1.equals("EMPTY") && s2.equals("EMPTY")) 
            board[pr1][pc1] = board[pr2][pc2] = s1;
        
		else board[pr1][pc1] = board[pr2][pc2] = s1;
        
        merge(r1, c1, r2, c2);
    }
    
    void unmerge(int r, int c) {
        int n = find(r, c);
        int rr = n / 50; 
        int rc = n % 50;
        
        String tmp = board[rr][rc];
        
        List<Integer> removeList = new ArrayList<>();
        for(int i = 0; i < 50; i++) {
            for(int j = 0; j < 50; j++) {
                int cur = find(i, j);
                if(cur == n) {
                    board[i][j] = "EMPTY";
                    removeList.add(i * 50 + j);
                }
            }
        }
        for(int target : removeList) {
           	int row = target / 50;
            int col = target % 50;
            parent[row][col] = target;
        }
        board[r][c] =  tmp;
    }
    
    String print(int r, int c) {
        int n = find(r, c);
        r = n / 50;
        c = n % 50;
        return board[r][c];
    }
    
    public String[] solution(String[] commands) {
        
        List<String> res = new ArrayList<>();
        
        for(int i = 0; i <= 50; i++) {
            for(int j = 0; j <= 50; j++) {
                parent[i][j] = i * 50 + j;
                board[i][j] = "EMPTY";
            }
        }
      	
        for(int i = 0; i < commands.length; i++) {
        	String[] input = commands[i].split(" ");
            
            if(input[0].equals("UPDATE")) {
               if(input.length == 4) {
               		int r = Integer.parseInt(input[1]); 
               		int c = Integer.parseInt(input[2]); 
                  	updateOne(r - 1, c - 1, input[3]);
               } else {
                  	updateAll(input[1], input[2]); 
               }
            } else if(input[0].equals("MERGE")) {
               	int r1 = Integer.parseInt(input[1]); 
               	int c1 = Integer.parseInt(input[2]); 
               	int r2 = Integer.parseInt(input[3]); 
               	int c2 = Integer.parseInt(input[4]); 
                mergeCell(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
            } else if(input[0].equals("UNMERGE")) {
               	int r = Integer.parseInt(input[1]); 
               	int c = Integer.parseInt(input[2]); 
                unmerge(r - 1, c - 1);
            } else if(input[0].equals("PRINT")) {
               	int r = Integer.parseInt(input[1]); 
               	int c = Integer.parseInt(input[2]); 
                String ret = print(r - 1, c - 1);
                res.add(ret);
            }
        }
        
        
        return res.stream().toArray(String[]::new);
    }
}