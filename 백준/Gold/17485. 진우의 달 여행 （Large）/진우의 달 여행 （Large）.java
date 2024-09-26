import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static int[][] board = new int[1001][1001];
    static int[][][] dp = new int[1001][1001][3];

    static boolean xInRange(int x) {
        return 0 <= x && x < m;
    }

    static int dfs(int y, int x, int dir) {
        if(!xInRange(x)) return 987654321; 
        else if(y == n) return 0;

        if(dp[y][x][dir] != -1) {
            return dp[y][x][dir];
        }

        int ret = 987654321;

        if(dir != 0) ret = Math.min(ret, dfs(y + 1, x - 1, 0));
        if(dir != 1) ret = Math.min(ret, dfs(y + 1, x, 1));
        if(dir != 2) ret = Math.min(ret, dfs(y + 1, x + 1, 2));
        return dp[y][x][dir] = board[y][x] + ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                Arrays.fill(dp[i][j], -1); 

        int res = 987654321;
        for(int j = 0; j < m; j++) {
            for(int dir = 0; dir < 3; dir++)
                res = Math.min(res, dfs(0, j, dir));
        }

        bw.write(String.valueOf(res));

        bw.flush();
        bw.close();
    }
}
