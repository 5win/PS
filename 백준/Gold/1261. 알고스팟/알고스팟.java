import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int fir, sec, third;
        public Pair(int a, int b, int c) {
            fir = a;
            sec = b;
            third = c;
        } 
    }

    static int n, m;
    static String[] board;
    static int[][] dist;
    static final int INF = Integer.MAX_VALUE;
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    static void bfs() {
        Deque<Pair> dq = new ArrayDeque<>();
        dq.offerLast(new Pair(0, 0, 0));
        for(int i = 0; i < n; i++)
            Arrays.fill(dist[i], INF);
        dist[0][0] = 0;

        while(!dq.isEmpty()) {
            Pair cNode = dq.pollFirst();

            int y = cNode.fir, x = cNode.sec;
            int cost = cNode.third;
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx)) continue;

                if(board[ny].charAt(nx) == '1' && dist[ny][nx] > cost + 1) {
                    dist[ny][nx] = cost + 1;
                    dq.offerLast(new Pair(ny, nx, cost + 1));

                } else if(board[ny].charAt(nx) == '0' && dist[ny][nx] > cost) {
                    dist[ny][nx] = cost;
                    dq.offerFirst(new Pair(ny, nx, cost));
                }
            }
        }
    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        m = Integer.parseInt(input[0]);
        n = Integer.parseInt(input[1]);

        board = new String[n];
        dist = new int[n][m];

        for(int i = 0; i < n; i++) {
            board[i] = br.readLine();
        }

        bfs();
        bw.write(dist[n - 1][m - 1] + "\n");

        bw.flush();
        bw.close();
    }
}
