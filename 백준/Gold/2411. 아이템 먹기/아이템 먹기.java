import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m, a, b;
    static int[][][] dp;
    static int[][] board;

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    static int dfs(int remain, int y, int x) {

        if(y == n - 1 && x == m - 1) {
            if(remain == 0) return 1;
            return 0;
        }

        if(dp[remain][y][x] != -1)
            return dp[remain][y][x];

        int ret = 0;
        if(inRange(y + 1, x) && board[y + 1][x] != 2) {
            if(board[y + 1][x] == 1)
                ret += dfs(remain - 1, y + 1, x);
            else
                ret += dfs(remain, y + 1, x);
        }
        if(inRange(y, x + 1) && board[y][x + 1] != 2) {
            if(board[y][x + 1] == 1)
                ret += dfs(remain - 1, y, x + 1);
            else
                ret += dfs(remain, y, x + 1);
        }

        return dp[remain][y][x] = ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        a = Integer.parseInt(input[2]);
        b = Integer.parseInt(input[3]);

        board = new int[n][m];
        dp = new int[a + 1][n][m];
        for(int i = 0; i <  a + 1; i++) {
            for(int j = 0; j < n; j++)
                Arrays.fill(dp[i][j], -1);
        }


        for(int i = 0; i < a; i++) {
            input = br.readLine().split(" ");
            int y = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            y--; x--;
            board[y][x] = 1;
        }

        for(int i = 0; i < b; i++) {
            input = br.readLine().split(" ");
            int y = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            y--; x--;
            board[y][x] = 2;
        }

        int res = dfs(a, 0, 0);
        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
