import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static class Pair {
        int y, x;
        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    
    static int n, m;
    static int[][] board = new int[1001][1001];
    static Pair start;
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    static int[][] visited = new int[1001][1001];

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    static void bfs() {
        Queue<Pair> q = new LinkedList<>();
        visited[start.y][start.x] = 1;
        q.offer(start);

        while(!q.isEmpty()) {
            Pair here = q.peek();
            q.poll();

            int y = here.y, x = here.x;
            for(int dir = 0; dir < 4; dir++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(ny, nx) || board[ny][nx] != 1 || visited[ny][nx] != 0) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.offer(new Pair(ny, nx));
            } 
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = sc.nextInt();
                if(board[i][j] == 2) {
                    start = new Pair(i, j);
                }
            }
        }
        bfs();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && board[i][j] == 1)
                    System.out.print("-1 ");
                else if(visited[i][j] == 0)
                    System.out.print("0 ");
                else 
                    System.out.print(visited[i][j] - 1 + " ");
            }
            System.out.println();
        }
    }
}
