class Solution {
    public int solution(String[][] board, int h, int w) {
        
        int[] dy = {0, 1, 0, -1};
        int[] dx = {1, 0, -1, 0};
        
        int res = 0;
        for(int dir = 0; dir < 4; dir++) {
           	int ny = h + dy[dir], nx = w + dx[dir];
            if(!(0 <= ny && ny < board.length && 0 <= nx && nx < board[0].length)) continue;
            if(!board[ny][nx].equals(board[h][w])) continue;
            res++;
        }
        return res;
    }
}