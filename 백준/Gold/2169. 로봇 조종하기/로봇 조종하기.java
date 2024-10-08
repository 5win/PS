import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int n, m;
    static int[][] board;
    static int[][][] dp;
    static boolean[][] visited;
    static int[] dy = {0, 1, 0};
    static int[] dx = {1, 0, -1};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    static int dfs(int y, int x, int prevDir) {
        if(y == n - 1 && x == m - 1) {
            return board[y][x];
        }

        if(dp[y][x][prevDir] != Integer.MIN_VALUE)
            return dp[y][x][prevDir];

        int ret = Integer.MIN_VALUE;
        for(int dir = 0; dir < 3; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            ret = Math.max(ret, dfs(ny, nx, dir));
            visited[ny][nx] = false;
        }
        if(ret == Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return dp[y][x][prevDir] = ret + board[y][x];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        board = new int[n][m];
        dp = new int[n][m][3];
        visited = new boolean[n][m];

        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                Arrays.fill(dp[i][j], Integer.MIN_VALUE);

        visited[0][0] = true;
        int res = dfs(0, 0, 0);
        bw.write(res + "\n");

        bw.flush();
        bw.close();
    }
}
