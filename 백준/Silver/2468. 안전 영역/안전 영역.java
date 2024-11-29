import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int fir, sec;
        public Pair(int a, int b) {
            fir = a;
            sec = b;
        }
    }

    static int n;
    static int[][] board;
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    static void bfs(boolean[][] isFull, int r, int c) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(r, c));
        isFull[r][c] = true;

        while(!q.isEmpty()) {
            Pair here = q.poll();

            int y = here.fir, x = here.sec;

            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || isFull[ny][nx]) continue;
                isFull[ny][nx] = true;
                q.offer(new Pair(ny, nx));
            }
        }
    }

    static int calcCnt(boolean[][] isFull) {

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <n; j++) {
                if(isFull[i][j]) continue;
                cnt++;
                bfs(isFull, i, j);
            }
        }
        return cnt;
    }

    static boolean[][] rain(int h) {
        boolean[][] isFull = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] <= h)
                    isFull[i][j] = true;
            }
        }
        return isFull;
    }

    static int solve() {
        int max = 0;
        for(int h = 0; h <= 100; h++) {
            boolean[][] isFull = rain(h);
            max = Math.max(max, calcCnt(isFull));
        }
        return max;
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        board = new int[n][n];

        String[] input;
        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        bw.write(solve() + "\n");

        bw.flush();
        bw.close();
    }
}
