import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir, sec, thir;
        public Pair(int a, int b, int c) {
            fir = a;
            sec = b;
            thir = c;
        }
        public int compareTo(Pair p) {
            return thir - p.thir;
        }
    }

    static int n;
    static int[][] board = new int[126][126];
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    static int[][] dist = new int[126][126];

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for(int i = 0; i < 126; i++) Arrays.fill(dist[i], Integer.MAX_VALUE);
        dist[0][0] = board[0][0];
        pq.offer(new Pair(0, 0, board[0][0]));

        while(!pq.isEmpty()) {
            Pair here = pq.peek();
            pq.poll();

            int y = here.fir, x = here.sec;

            if(dist[y][x] < here.thir) continue;

            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx)) continue;
                int nextCost = here.thir + board[ny][nx];
                if(dist[ny][nx] <= nextCost) continue;
                dist[ny][nx] = nextCost;
                pq.offer(new Pair(ny, nx, nextCost));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = 0;
        while(true) {
            T++;
            n = Integer.parseInt(br.readLine());
            if(n == 0) break;
            for(int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                for(int j = 0; j < n; j++)
                    board[i][j] = Integer.parseInt(input[j]);
            }
            dijkstra();
            bw.write("Problem " + T + ": " + String.valueOf(dist[n - 1][n - 1]) + "\n");
        }


        bw.flush();
        bw.close();
    }
}
