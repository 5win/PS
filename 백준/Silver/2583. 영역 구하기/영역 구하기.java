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

    static int m, n, k;
    static boolean[][] visited;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static void drawRec(int x1, int y1, int x2, int y2) {
        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                visited[i][j] = true;
            }
        }
    }

    static boolean inRange(int y, int x) {
        return 0 <= y && y < m && 0 <= x && x < n;
    }

    static int bfs(int y, int x) {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(y, x));
        visited[y][x] = true;
        int cnt = 1;

        while(!q.isEmpty()) {
            Pair here = q.poll();
            int cy = here.fir, cx = here.sec;

            for(int dir = 0; dir < 4; dir++) {
                int ny = cy + dy[dir], nx = cx + dx[dir];
                if(!inRange(ny, nx) || visited[ny][nx]) continue;
                visited[ny][nx] = true;
                q.offer(new Pair(ny, nx));
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        m = Integer.parseInt(input[0]);
        n = Integer.parseInt(input[1]);
        k = Integer.parseInt(input[2]);

        visited = new boolean[m][n];

        for(int i = 0; i < k; i ++) {
            input = br.readLine().split(" ");
            int x1 = Integer.parseInt(input[0]);
            int y1 = Integer.parseInt(input[1]);
            int x2 = Integer.parseInt(input[2]);
            int y2 = Integer.parseInt(input[3]);
            drawRec(x1, y1, x2, y2);
        }

        int cnt = 0;
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j]) continue;
                cnt++;
                int ret = bfs(i, j);
                res.add(ret);
            }
        }
        Collections.sort(res);

        bw.write(cnt + "\n");
        for(int i : res) {
            bw.write(i + " ");
        }

        bw.flush();
        bw.close();
    }
}
