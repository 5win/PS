class Solution {
    
    public int checkBingo(String[] arr, char c) {
        int ret = 0;
        // row
        for(int i = 0; i < 3; i++) {
            if(arr[i].charAt(0) == c && arr[i].charAt(1) == c && arr[i].charAt(2) == c) {
              	ret++;  
            }
        }
        
        // col
        for(int j = 0; j < 3; j++) {
            if(arr[0].charAt(j) == c && arr[1].charAt(j) == c && arr[2].charAt(j) == c) {
                ret++;
            }
        }
        
        // diagonal
        if(arr[0].charAt(0) == c && arr[1].charAt(1) == c && arr[2].charAt(2) == c) {
            ret++;
        }
            
        if(arr[0].charAt(2) == c && arr[1].charAt(1) == c && arr[2].charAt(0) == c) {
            ret++;
        }
        return ret;
    }
    
    public int solution(String[] board) {
        
        int ocnt = 0, xcnt = 0;
        for(int i = 0; i < board.length; i++) {
            for(int j = 0; j < board[0].length(); j++) {
        		if(board[i].charAt(j) == 'O') {
                    ocnt++;
                } else if(board[i].charAt(j) == 'X') {
                    xcnt++;
                }
            }
        }
		        
        int diaO = checkBingo(board, 'O');
        int diaX = checkBingo(board, 'X');
        if(diaO > 0 && diaX > 0) {
            return 0;
        }
        
        if(diaX > 0 && ocnt > xcnt) {
           	return 0; 
        }
        if(diaO > 0 && ocnt == xcnt) {
            return 0;
        }
        
 		if(ocnt != xcnt + 1 && ocnt != xcnt) {
            return 0;
        }       
        return 1;
    }
}