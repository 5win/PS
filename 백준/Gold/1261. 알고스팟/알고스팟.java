import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair implements Comparable<Pair> {
        int fir, sec, third;
        public Pair(int a, int b, int c) {
            fir = a;
            sec = b;
            third = c;
        } 

        public int compareTo(Pair p) {
            return third - p.third;
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

    static void dijkstra() {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(0, 0, 0));
        for(int i = 0; i < n; i++)
            Arrays.fill(dist[i], INF);
        dist[0][0] = 0;
    
        while(!pq.isEmpty()) {
            Pair curNode = pq.poll();

            int y = curNode.fir, x = curNode.sec;
            int cost = curNode.third;

            if(dist[y][x] < cost) continue;

            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx)) continue;
                int nextCost = cost;
                if(board[ny].charAt(nx) == '1')
                    nextCost++;
                if(dist[ny][nx] <= nextCost) continue;
                dist[ny][nx] = nextCost;
                pq.offer(new Pair(ny, nx, nextCost));
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

        dijkstra();
        bw.write(dist[n - 1][m - 1] + "\n");

        bw.flush();
        bw.close();
    }
}
