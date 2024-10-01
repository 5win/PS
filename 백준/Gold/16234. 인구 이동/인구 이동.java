import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int y, x;
        public Pair(int a, int b) {
            y = a;
            x = b;
        }
    }

    static int n, l, r;
    static int[][] board = new int[51][51];
    static boolean[][] visited = new boolean[51][51];
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    
    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    static boolean bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        visited[y][x] = true;
        q.offer(new Pair(y, x));

        boolean isMoved = false;
        int sum = board[y][x];
        List<Pair> uni = new ArrayList<>();
        uni.add(new Pair(y, x));

        while(!q.isEmpty()) {
            Pair here = q.peek();
            q.poll();

            int cy = here.y, cx = here.x;
            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir], nx = cx + dx[dir];
                if(!inRange(ny, nx) || visited[ny][nx]) continue;

                int gap = Math.abs(board[cy][cx] - board[ny][nx]);
                if(gap < l || r < gap) continue;

                isMoved = true; 
                uni.add(new Pair(ny, nx));
                sum += board[ny][nx];
                visited[ny][nx] = true;
                q.offer(new Pair(ny, nx));
            }
        }

        int newPop = sum / uni.size();
        for(Pair p : uni) {
            board[p.y][p.x] = newPop;
        }
        return isMoved;
    }

    static void print() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                System.out.print(board[i][j]);
            System.out.println();
        }
        System.out.println();
    }

    static int solve() {
        int date = 0;
        boolean isMoved = false;
        while(true) {
            for(int i = 0; i < n; i++) Arrays.fill(visited[i], false);

            isMoved = false;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(visited[i][j]) continue;
                    isMoved = bfs(i, j) || isMoved;
                }
            }
            if(!isMoved) break;
            date++;
        }
        return date;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        l = Integer.parseInt(input[1]);
        r = Integer.parseInt(input[2]);
        for(int i = 0; i < n; i++) {
            input = br.readLine().split(" ");
            for(int j = 0; j < n; j++)
                board[i][j] = Integer.parseInt(input[j]);
        }

        bw.write(String.valueOf(solve()));

        bw.flush();
        bw.close();
    }
}
