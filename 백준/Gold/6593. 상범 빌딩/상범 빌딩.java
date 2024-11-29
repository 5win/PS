import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.io.*;

public class Main {

    static int l, r, c;
    static String[][] board;
    static int[] src, dst;

    static int[] dy = {0, 1, 0, -1, 0, 0};
    static int[] dx = {1, 0, -1, 0, 0, 0};
    static int[] dz = {0, 0, 0, 0, 1, -1};

    static boolean inRange(int z, int y, int x) {
        return 0 <= z && z < l &&  0 <= y && y < r && 0 <= x && x < c;
    }

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        int[][][] visited = new int[l][r][c];
        
        for(int i = 0; i < l; i++)
            for(int j = 0; j < r; j++)
                Arrays.fill(visited[i][j], -1);

        q.offer(src);
        visited[src[0]][src[1]][src[2]] = 0;

        while(!q.isEmpty()) {
            int[] here = q.poll();
            int z = here[0], y = here[1], x = here[2];
            
            for(int dir = 0; dir < 6; dir++) {
                int nz = z + dz[dir], ny = y + dy[dir], nx = x + dx[dir];
                if(!inRange(nz, ny, nx) || visited[nz][ny][nx] != -1 || board[nz][ny].charAt(nx) == '#') continue;
                visited[nz][ny][nx] = visited[z][y][x] + 1;
                q.offer(new int[]{nz, ny, nx});
            }
        }
        return visited[dst[0]][dst[1]][dst[2]];
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            String[] input = br.readLine().split(" ");
            l = Integer.parseInt(input[0]);
            r = Integer.parseInt(input[1]);
            c = Integer.parseInt(input[2]);

            if(l + r + c == 0) break;

            board = new String[l][r];

            for(int i = 0; i < l; i++) {
                for(int j = 0; j < r; j++) {
                    board[i][j] = br.readLine();
                    for(int k = 0; k < c; k++) {
                        if(board[i][j].charAt(k) == 'S') {
                            src = new int[]{i, j, k};
                        } else if(board[i][j].charAt(k) == 'E') {
                            dst = new int[]{i, j, k};
                        }
                    }
                }
                br.readLine();
            }

            int res = bfs();
            if(res == -1) {
                bw.write("Trapped!\n");
            } else {
                bw.write("Escaped in " + res + " minute(s).\n");
            }
        }

        bw.flush();
        bw.close();
    }
}
