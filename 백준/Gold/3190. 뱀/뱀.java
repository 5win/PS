import java.util.*;
import java.io.*;

public class Main {

    static class Pair {
        public int y, x, dir;

        public Pair(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }


    static int n, k, l;
    static boolean[][] apple = new boolean[101][101];
    static boolean[][] visited = new boolean[101][101];
    static Map<Integer, Character> map = new HashMap<>();
    static Deque<Pair> deque = new ArrayDeque<>();
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};

    static boolean inRange(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }

    static int solve() {
        deque.offer(new Pair(0, 0, 0));
        visited[0][0] = true;

        int t = 0;
        while(true) {
            t++;
            Pair head = deque.getFirst();
            int dir = head.dir;

            int ny = head.y + dy[dir], nx = head.x + dx[dir];
            if(!inRange(ny, nx) || visited[ny][nx]) break;

            // t초 일땐 일단 현재 방향 그대로 다음 위치.
            // 다음 위치 정한 뒤에 방향 전환
            if(map.containsKey(t)) {
                char nd = map.get(t);
                if(nd == 'L') dir = (dir + 4 - 1) % 4;
                else dir = (dir + 1) % 4;
            } 

            visited[ny][nx] = true;
            deque.offerFirst(new Pair(ny, nx, dir));
            if(!apple[ny][nx]) {
                Pair tail = deque.getLast();
                visited[tail.y][tail.x] = false;
                deque.pollLast();
            }
            apple[ny][nx] = false;
        }
        return t;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        for(int i = 0; i < k; i++) {
            String[] input = br.readLine().split(" ");
            int r = Integer.parseInt(input[0]);
            int c = Integer.parseInt(input[1]);
            apple[r - 1][c - 1] = true;
        }
        l = Integer.parseInt(br.readLine());
        for(int i = 0; i < l; i++) {
            String[] input = br.readLine().split(" ");
            int t = Integer.parseInt(input[0]);
            map.put(t, input[1].charAt(0));
        }

        int res = solve();
        bw.write(String.valueOf(res));
        bw.newLine();
        bw.flush();
        bw.close();
    }
}