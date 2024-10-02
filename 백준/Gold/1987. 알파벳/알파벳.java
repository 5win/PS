import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int r, c;
    static String[] board = new String[21];
    static boolean[] alpha = new boolean[26];
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    static int res = 0;

    static boolean inRange(int y, int x) {
        return 0 <= y && y < r && 0 <= x && x < c;
    }

    static void dfs(int y, int x, int len) {

        for(int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || alpha[board[ny].charAt(nx) - 'A']) continue;
            alpha[board[ny].charAt(nx) - 'A'] = true;
            dfs(ny, nx, len + 1);
            alpha[board[ny].charAt(nx) - 'A'] = false;
        }
        res = Math.max(res, len);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        for(int i = 0; i < r; i++)
            board[i] = br.readLine();

        alpha[board[0].charAt(0) - 'A'] = true;
        dfs(0, 0, 1);
        bw.write(String.valueOf(res));

        bw.flush();
        bw.close();
    }
}
