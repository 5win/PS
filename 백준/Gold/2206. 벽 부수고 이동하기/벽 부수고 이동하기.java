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

    static int n, m;
    static String[] board;
    static int[] dy = {0 ,1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    static void bfs(int[][] dist, int srcY, int srcX) {
        for(int i = 0; i < dist.length; i++) Arrays.fill(dist[i], -1);
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(srcY, srcX));
        dist[srcY][srcX] = 1;       // 시작, 끝 칸 포함이므로

        while(!q.isEmpty()) {
            Pair here = q.peek();
            q.poll();

            int y = here.fir, x = here.sec;
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                // 벽을 방문은 하되, 큐에 넣진 않도록
                if(!inRange(ny, nx) || dist[ny][nx] != -1) continue;
                dist[ny][nx] = dist[y][x] + 1;
                if(board[ny].charAt(nx) == '1') continue;
                q.offer(new Pair(ny, nx));
            }
        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);
        board = new String[n];

        for(int i = 0; i < n; i++) {
            board[i] = br.readLine();
        }
        int[][] sDist = new int[n][m];
        int[][] dDist = new int[n][m];
        bfs(sDist, 0, 0);
        bfs(dDist, n - 1, m - 1);

        int res = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i].charAt(j) == '1' && sDist[i][j] != -1 && dDist[i][j] != -1) {
                    res = Math.min(res, sDist[i][j] + dDist[i][j] - 1);
                }
            }
        }
        if(sDist[n - 1][m - 1] != -1)
            res = Math.min(res, sDist[n - 1][m - 1]);

        if(res == Integer.MAX_VALUE && sDist[n - 1][m - 1] == -1)
            bw.write("-1");
        else
            bw.write(String.valueOf(res));

        bw.flush();
        bw.close();
    }
}
