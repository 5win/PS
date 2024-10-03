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

    static int r, c;
    static String[] board;
    static int[][] fired;
    static int[][] visited;
    static Queue<Pair> q = new LinkedList<>();
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < r && 0 <= x && x < c;
    }

    static void fireBfs() {
        while(!q.isEmpty()) {
            Pair here = q.peek();
            q.poll();

            int y = here.y, x = here.x;
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || fired[ny][nx] != 0 || board[ny].charAt(nx) == '#') continue;
                fired[ny][nx] = fired[y][x] + 1;
                q.offer(new Pair(ny, nx));
            }
        } 
    }

    static int moveBfs() {
        while(!q.isEmpty()) {
            Pair here = q.peek();
            q.poll();

            int y = here.y, x = here.x;
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx)) {
                    return visited[y][x] + 1;
                }
                if(visited[ny][nx] != 0 || board[ny].charAt(nx) == '#') continue;
                if(fired[ny][nx] != 0 && fired[ny][nx] <= visited[y][x] + 1) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.offer(new Pair(ny, nx));
            }
        } 
        return -1;
    }

    static int solve() {
        // fire
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i].charAt(j) == 'F') {
                    q.offer(new Pair(i, j));
                    fired[i][j] = 1;
                }
            }
        }
        fireBfs();

        q.clear(); 
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i].charAt(j) == 'J') {
                    q.offer(new Pair(i, j));
                    visited[i][j] = 1;
                    break;
                }
            }
        }
        int time = moveBfs();
        return time;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        r = Integer.parseInt(input[0]);
        c = Integer.parseInt(input[1]);
        fired = new int[r][c];
        visited = new int[r][c];
        board = new String[r];

        for(int i = 0; i < r; i++) 
            board[i] = br.readLine();

        int time = solve();
        if(time == -1) {
            bw.write("IMPOSSIBLE\n");
        } else {
            bw.write(String.valueOf(time - 1));
        }
        bw.flush();
        bw.close();
    }
}
