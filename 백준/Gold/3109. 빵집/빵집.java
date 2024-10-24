import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int r, c;
    static String[] board;
    static boolean[][] visited;
    static int[] dy = {-1, 0, 1};
    static int[] dx = {1, 1, 1};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < r && 0 <= x && x < c;
    }

    static boolean dfs(int y, int x) {
        if(x == c - 1) {
            return true;
        }

        boolean ret = false;
        for(int dir = 0; dir < 3; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx) || visited[ny][nx] || board[ny].charAt(nx) == 'x') continue;
            visited[ny][nx] = true;
            ret = ret || dfs(ny, nx);
            
            if(ret) break;
        }
        return ret;
    }

    static int solve() {

        int cnt = 0;
        for(int i = 0; i < r; i++) {
            if(dfs(i, 0)) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        board = new String[r];
        visited = new boolean[r][c];

        for(int i = 0; i < r; i++) {
            board[i] = br.readLine();
        }

        int res = solve();
        bw.write(res + "\n");


        bw.flush();
        bw.close();
    }
}
