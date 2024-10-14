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
    static StringBuilder[] board;
    static boolean[][] visited;
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    static void bfs(int r, int c) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(r, c));
        visited[r][c] = true;

        char color = board[r].charAt(c);
        while(!q.isEmpty()) {
            Pair here = q.poll();
            int y = here.fir, x = here.sec;

            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || visited[ny][nx] || board[ny].charAt(nx) != color) continue;
                visited[ny][nx] = true;
                q.offer(new Pair(ny, nx));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        board = new StringBuilder[n];
        visited = new boolean[n][n];

        for(int i = 0; i < n; i++) {
            board[i] = new StringBuilder(br.readLine());
        }

        int nonCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) continue;
                bfs(i, j);
                nonCnt++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i].charAt(j) == 'G')
                    board[i].setCharAt(j, 'R');
            }
            Arrays.fill(visited[i], false);
        }

        int rgCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) continue;
                bfs(i, j);
                rgCnt++;
            }
        }

        bw.write(nonCnt + " " + rgCnt);

        bw.flush();
        bw.close();
    }
}
